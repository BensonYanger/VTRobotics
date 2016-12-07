#include "vexstdinc.h"

#include "driver.h"

#include "drive.h"
#include "audio.h"
#include "lift.h"

/*-----------------------------------------------------------------------------*/
/** @brief      Driver control                                                 */
/*-----------------------------------------------------------------------------*/
/** @details
 *  This thread is started when the driver control period is started
 */

msg_t
vexOperator( void *arg )
{
	startxDrive();
	startSpeakerPress();

	int16_t blinkr = 0;
	int16_t blinky = 0;
	int16_t blinkg = 0;

	int16_t	armLock = 0;

	(void)arg;

	// Must call this
	vexTaskRegister("operator");

	// Run until asked to terminate
	while(!chThdShouldTerminate())
		{
		// flash led/digi out
		vexDigitalPinSet( kVexDigital_1, (blinkr++ >> 2) & 1);
		vexDigitalPinSet( kVexDigital_2, (blinky++ >> 2) & 1);
		vexDigitalPinSet( kVexDigital_3, (blinkg++ >> 2) & 1);

		// status on LCD of encoder and sonar
		vexLcdPrintf( VEX_LCD_DISPLAY_2, VEX_LCD_LINE_1, "%4.2fV   %8.1f", vexSpiGetMainBattery() / 1000.0, chTimeNow() / 1000.0 );
		vexLcdPrintf( VEX_LCD_DISPLAY_2, VEX_LCD_LINE_2, "Enc %6d", vexEncoderGet(kVexQuadEncoder_1));

		vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "P %4d LT %4d", vexAdcGet(1), vexAdcGet(2));
		vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "");

		/* CLAW ARM */
		if(vexControllerGet(Btn6U)) {
			vexMotorSet(kVexMotor_2, 127);
			vexMotorSet(kVexMotor_9, 127);
		} else if (vexControllerGet(Btn6D)) {
			vexMotorSet(kVexMotor_2, -127);
			vexMotorSet(kVexMotor_9, -127);
		} else {
			vexMotorSet(kVexMotor_2, 0);
			vexMotorSet(kVexMotor_9, 0);
		}

		/* CLAW */
		if(vexControllerGet(Btn5U)) {
			vexMotorSet(kVexMotor_1, 127);
			vexMotorSet(kVexMotor_10, 127);
		} else if (vexControllerGet(Btn5D)) {
			vexMotorSet(kVexMotor_1, -127);
			vexMotorSet(kVexMotor_10, -127);
		} else {
			vexMotorSet(kVexMotor_1, 0);
			vexMotorSet(kVexMotor_10, 0);
		}

		if(vexWatchdogResetFlagGet()) {
			vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, " Watchdog Reset ");
		}

		// Don't hog cpu
		vexSleep( 25 );
		}

	return (msg_t)0;
}