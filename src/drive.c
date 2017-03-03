#include "vexstdinc.h"

#include "drive.h"

const unsigned int TrueSpeed[128] =
{
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0, 21, 21, 21, 22, 22, 22, 23, 24, 24,
    25, 25, 25, 25, 26, 27, 27, 28, 28, 28,
    28, 29, 30, 30, 30, 31, 31, 32, 32, 32,
    33, 33, 34, 34, 35, 35, 35, 36, 36, 37,
    37, 37, 37, 38, 38, 39, 39, 39, 40, 40,
    41, 41, 42, 42, 43, 44, 44, 45, 45, 46,
    46, 47, 47, 48, 48, 49, 50, 50, 51, 52,
    52, 53, 54, 55, 56, 57, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 67, 68, 70,
    71, 72, 72, 73, 74, 76, 77, 78, 79, 79,
    80, 81, 83, 84, 84, 86, 86, 87, 87, 88,
    88, 89, 89, 90, 90,127,127,127
};

/* SPEED GEARED MOTORS */
int trueSpeedS(int rawValue){
	return (rawValue > 0 ? 1 : -1) * TrueSpeed[abs(rawValue)];
}

static WORKING_AREA(waTankDrive, 512);
msg_t
tankDrive(void *arg) 
{
    int16_t joyLy = 0;
    int16_t joyRy = 0;

    (void)arg;

    // Register the task
    vexTaskRegister("tankdrive");

    while(!chThdShouldTerminate()) 
    {
        joyLy = vexControllerGet(Ch3);
        joyRy = vexControllerGet(Ch2);

        vexMotorSet(kVexMotor_4, joyLy);
        vexMotorSet(kVexMotor_7, joyLy);

        vexMotorSet(kVexMotor_5, joyRy);
        vexMotorSet(kVexMotor_6, joyRy);

        // Don't hog cpu
        vexSleep(25);
    }

    return (msg_t)0;
}

static WORKING_AREA(waxDrive, 512);
msg_t
xDrive(void *arg) 
{
    int16_t joyLx = 0;
    int16_t joyLy = 0;
    int16_t joyRy = 0;
    int16_t joyRx = 0;

    (void)arg;

    // Register the task
    vexTaskRegister("xdrive");

    while(!chThdShouldTerminate()) 
    {
        joyLx = vexControllerGet(Ch4);
        joyLy = vexControllerGet(Ch3);
        joyRy = vexControllerGet(Ch2);
        joyRx = vexControllerGet(Ch1);

        if(abs(joyLy) > 10 && abs(joyLx) < abs(joyLy)) {
            vexMotorSet(kVexMotor_4, trueSpeedS(joyLy));
            vexMotorSet(kVexMotor_6, trueSpeedS(joyLy));

            vexMotorSet(kVexMotor_5, trueSpeedS(joyLy));
            vexMotorSet(kVexMotor_7, trueSpeedS(joyLy));
        } else if(abs(joyLx) > 10 && abs(joyLx) > abs(joyLy)) {
            vexMotorSet(kVexMotor_4, trueSpeedS(-joyLx));
            vexMotorSet(kVexMotor_6, trueSpeedS(-joyLx));
            
            vexMotorSet(kVexMotor_5, trueSpeedS(joyLx));
            vexMotorSet(kVexMotor_7, trueSpeedS(joyLx));
        } else if(abs(joyRx) > 10) {
            vexMotorSet(kVexMotor_4, trueSpeedS(joyRx));
            vexMotorSet(kVexMotor_6, trueSpeedS(-joyRx));
            
            vexMotorSet(kVexMotor_5, trueSpeedS(-joyRx));
            vexMotorSet(kVexMotor_7, trueSpeedS(joyRx));
        } else {
            vexMotorSet(kVexMotor_4, 0);
            vexMotorSet(kVexMotor_6, 0);
            
            vexMotorSet(kVexMotor_5, 0);
            vexMotorSet(kVexMotor_7, 0);
        }

        // Don't hog cpu
        vexSleep(25);
    }

    return (msg_t)0;
}

int
startTankDrive(void) {
    // start tank drive
    chThdCreateStatic(waTankDrive, sizeof(waTankDrive), NORMALPRIO - 1, tankDrive, NULL);
    return 0;
}

int
startxDrive(void) {
    // start tank drive
    chThdCreateStatic(waxDrive, sizeof(waxDrive), NORMALPRIO - 1, xDrive, NULL);
    return 0;
}