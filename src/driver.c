#include "vexstdinc.h"

#include "driver.h"

/*-----------------------------------------------------------------------------*/
/** @brief      Driver control                                                 */
/*-----------------------------------------------------------------------------*/
/** @details
 *  This thread is started when the driver control period is started
 */

#define MotorDriveL     kVexMotor_1
#define MotorDriveR     kVexMotor_10

msg_t
vexOperator( void *arg )
{
	int16_t		blink = 0;

	(void)arg;

	// Must call this
	vexTaskRegister("operator");

	// Run until asked to terminate
	while(!chThdShouldTerminate())
		{
		// flash led/digi out
		vexDigitalPinSet( kVexDigital_1, (blink++ >> 3) & 1);

		// status on LCD of encoder and sonar
		vexLcdPrintf( VEX_LCD_DISPLAY_2, VEX_LCD_LINE_1, "%4.2fV   %8.1f", vexSpiGetMainBattery() / 1000.0, chTimeNow() / 1000.0 );
		vexLcdPrintf( VEX_LCD_DISPLAY_2, VEX_LCD_LINE_2, "L %3d R %3d", vexMotorGet( MotorDriveL ), vexMotorGet( MotorDriveR ) );

		// Tank drive
		// left drive
		vexMotorSet( MotorDriveL, vexControllerGet( Ch3 ) );

		// right drive
		vexMotorSet( MotorDriveR, vexControllerGet( Ch2 ) );

		// Don't hog cpu
		vexSleep( 25 );
		}

	return (msg_t)0;
}