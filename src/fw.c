#include "main.h"
#include "fw.h"

// Update inteval (in mS) for the flywheel control loop
#define FW_LOOP_SPEED              25

// Maximum power we want to send to the flywheel motors
#define FW_MAX_POWER              127

// encoder counts per revolution depending on motor
#define MOTOR_269           240.448
#define MOTOR_393R          261.333
#define MOTOR_393S          392
#define MOTOR_393T          627.2
#define MOTOR_QUAD          360.0

// encoder tick per revolution
float           ticks_per_rev;          ///< encoder ticks per revolution

// Encoder
long            encoder_counts;         ///< current encoder count
long            encoder_counts_last;    ///< current encoder count

// velocity measurement
float           motor_speed;         ///< current velocity in rpm
long            time_last;          ///< Time of last velocity calculation

// TBH control algorithm variables
long            target_speed;        ///< target_velocity velocity
float           current_error;          ///< error between actual and target_velocity velocities
float           last_error;             ///< error last time update called
float           gain;                   ///< gain
float           driveTbh;                  ///< final drive out of TBH (0.0 to 1.0)
float           drive_at_zero;          ///< drive at last zero crossing
long            first_cross;            ///< flag indicating first zero crossing
float           drive_approx;           ///< estimated open loop drive

// final motor drive
long            motor_drive;            ///< final motor control value

//implement sgn since it does not exist in PROS
short sgn(const float input)
{
    if(input >= 0) {
    	return 1;
    }
    else if(input == 0) {
    	return 0;
    }
    else {
    	return -1;
    }
}

//set fw motors
void fwMotorSet(int motorPower)
{
    motorSet(FW1, motorPower);
    motorSet(FW2, -motorPower);
    motorSet(FW3, motorPower);
    motorSet(FW4, -motorPower);
}

/*-----------------------------------------------------------------------------*/
/** @brief      Get the flywheen motor encoder count                           */
/*-----------------------------------------------------------------------------*/
long fwMotorEncoderGet()
{
	long fw_encoder;
	fw_encoder = encoderGet(flywheel);
	return fw_encoder;
}

/*-----------------------------------------------------------------------------*/
/** @brief      Set the controller position                                    */
/** @param[in]  desired velocity                                               */
/** @param[in]  predicted_drive estimated open loop motor drive                */
/*-----------------------------------------------------------------------------*/
void fwVelocitySet( int speed, float predicted_drive )
{
    // set target_velocity velocity (motor rpm)
    target_speed = speed;

    // Set error so zero crossing is correctly detected
    current_error = target_speed - motor_speed;
    last_error    = current_error;

    // Set predicted open loop drive value
    drive_approx  = predicted_drive;
    // Set flag to detect first zero crossing
    first_cross   = 1;
    // clear tbh variable
    drive_at_zero = 0;
}

/*-----------------------------------------------------------------------------*/
/** @brief      Calculate the current flywheel motor velocity                  */
/*-----------------------------------------------------------------------------*/
void fwCalculateSpeed()
{
    int     delta_ms;
    int     delta_enc;

    // Get current encoder value
    encoder_counts = fwMotorEncoderGet();

    // This is just used so we don't need to know how often we are called
    // how many mS since we were last here
    delta_ms = millis() - time_last;
    time_last = millis();

    // Change in encoder count
    delta_enc = (encoder_counts - encoder_counts_last);

    // save last position
    encoder_counts_last = encoder_counts;

    // Calculate velocity in rpm
    motor_speed = (1000.0 / delta_ms) * delta_enc * 60.0 / ticks_per_rev / 5;
}

/*-----------------------------------------------------------------------------*/
/** @brief      Update the velocity tbh controller variables                   */
/*-----------------------------------------------------------------------------*/
void fwControlUpdateVelocityTbh()
{
    // calculate error in velocity
    // target_velocity is desired velocity
    // current is measured velocity
    current_error = target_speed - motor_speed;

    // Calculate new control value
    driveTbh = driveTbh + (current_error * gain);

    // Clip to the range 0 - 1.
    // We are only going forwards
    if( driveTbh > 1 )
          driveTbh = 1;
    if( driveTbh < 0 )
          driveTbh = 0;

    // Check for zero crossing
    if( sgn(current_error) != sgn(last_error) ) {
        // First zero crossing after a new set velocity command
        if( first_cross ) {
            // Set drive to the open loop approximation
            driveTbh = drive_approx;
            first_cross = 0;
        }
        else
            driveTbh = 0.5 * ( driveTbh + drive_at_zero );

        // Save this drive value in the "tbh" variable
        drive_at_zero = driveTbh;
    }

    // Save last error
    last_error = current_error;
}

/*-----------------------------------------------------------------------------*/
/** @brief     Task to control the velocity of the flywheel                    */
/*-----------------------------------------------------------------------------*/
void fwControl()
{
    // Set the gain
    gain = 0.00050;

    // We are using Torque geared motors
    // Set the encoder ticks per revolution
    ticks_per_rev = MOTOR_QUAD;

    while(1)
        {
        // Calculate velocity
        fwCalculateSpeed();

        // Do the velocity TBH calculations
        fwControlUpdateVelocityTbh() ;

        // Scale drive into the range the motors need
        motor_drive  = (driveTbh * FW_MAX_POWER) + 0.5;

        // Final Limit of motor values - don't really need this
        if( motor_drive >  127 ) motor_drive =  127;
        if( motor_drive < -127 ) motor_drive = -127;

        // and finally set the motor control value
        fwMotorSet( motor_drive );

        // Run at somewhere between 20 and 50mS
        delay(FW_LOOP_SPEED);
        }
}

// Main user task
void fwMain()
{
    char  str[32];

    lcdSetBacklight(uart2, 1);

    // Start the flywheel control task
    taskCreate(fwControl, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

    // Main user control loop
    while(1)
        {
        // Different speeds set by buttons
    	if(joystickGetDigital(1, 7, JOY_DOWN) == 1)
    		fwVelocitySet(125, 1.00);
    	if(joystickGetDigital(1, 8, JOY_UP) == 1)
    		fwVelocitySet(100, 0.70);
    	if(joystickGetDigital(1, 8, JOY_DOWN) == 1)
    		fwVelocitySet(90, 0.65);
    	if(joystickGetDigital(1, 8, JOY_UP) == 1 )
    	    fwVelocitySet(80, 0.60);
    	if(joystickGetDigital(1, 8, JOY_RIGHT) == 1 )
    	    fwVelocitySet(70, 0.50);
    	if(joystickGetDigital(1, 8, JOY_DOWN) == 1 )
    	    fwVelocitySet(62, 0.40);
    	if(joystickGetDigital(1, 8, JOY_LEFT) == 1 )
    	    fwVelocitySet(0, 0);

		if (target_speed == 0) {
			digitalWrite(10, HIGH);
			digitalWrite(11, HIGH);
			digitalWrite(12, HIGH);
		}
		else if (target_speed > motor_speed) {
			digitalWrite(10, LOW);
			digitalWrite(11, LOW);
			digitalWrite(12, HIGH);
		}
		else if (target_speed < motor_speed) {
			digitalWrite(10, HIGH);
			digitalWrite(11, LOW);
			digitalWrite(12, LOW);
		}

        // Display useful things on the LCD
        sprintf( str, "%4d %4d  %5.2f", target_speed,  motor_speed, powerLevelMain()/1000.0 );
        lcdSetText(uart2, 1, str );
        sprintf( str, "%4.2f %4.2f ", driveTbh, drive_at_zero );
        lcdSetText(uart2, 2, str );

        // Don't hog the cpu :)
        delay(10);
        }
}

