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
	int16_t clawLock = 0;

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
		vexLcdPrintf( VEX_LCD_DISPLAY_2, VEX_LCD_LINE_2, "LT %4d", vexAdcGet(kVexAnalog_3));

		vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "A %4d C %4d", vexAdcGet(kVexAnalog_5), vexAdcGet(kVexAnalog_7));
		vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "L %4d R %4d", vexEncoderGet(kVexQuadEncoder_1), vexEncoderGet(kVexQuadEncoder_2));

		/* ARM LOCK TOGGLE  */
		if(vexControllerGet(Btn8L) && armLock == 0) {
			armLock = 1;
			vexSleep(150);
		} else if(vexControllerGet(Btn8L) && armLock == 1) {
			armLock = 0;
			vexSleep(150);
		} else if(vexControllerGet(Btn8LXmtr2) && armLock == 0) {
			armLock = 1;
			vexSleep(150);
		} else if(vexControllerGet(Btn8LXmtr2) && armLock == 1) {
			armLock = 0;
			vexSleep(150);
		}

		/* CLAW LOCK TOGGLE */
		if(vexControllerGet(Btn8D) && clawLock == 0) {
			clawLock = 1;
			vexSleep(150);
		} else if(vexControllerGet(Btn8D) && clawLock == 1) {
			clawLock = 0;
			vexSleep(150);
		} else if(vexControllerGet(Btn8DXmtr2) && clawLock == 0) {
			clawLock = 1;
			vexSleep(150);
		} else if(vexControllerGet(Btn8DXmtr2) && clawLock == 1) {
			clawLock = 0;
			vexSleep(150);
		}

		/* CLAW ARM */
		if(vexControllerGet(Btn6U)) {
			vexMotorSet(kVexMotor_2, 127);
			vexMotorSet(kVexMotor_3, 127);
			vexMotorSet(kVexMotor_8, 127);
			vexMotorSet(kVexMotor_9, 127);
		} else if (vexControllerGet(Btn6D)) {
			vexMotorSet(kVexMotor_2, -127);
			vexMotorSet(kVexMotor_3, -127);
			vexMotorSet(kVexMotor_8, -127);
			vexMotorSet(kVexMotor_9, -127);
		/* XMTR 2 */
		} else if (vexControllerGet(Btn6UXmtr2)) {
			vexMotorSet(kVexMotor_2, 127);
			vexMotorSet(kVexMotor_3, 127);
			vexMotorSet(kVexMotor_8, 127);
			vexMotorSet(kVexMotor_9, 127);
		} else if (vexControllerGet(Btn6DXmtr2)) {
			vexMotorSet(kVexMotor_2, -127);
			vexMotorSet(kVexMotor_3, -127);
			vexMotorSet(kVexMotor_8, -127);
			vexMotorSet(kVexMotor_9, -127);
		/* ARM LOCK */
		} else if (armLock == 1) {
			vexSleep(50);
			vexMotorSet(kVexMotor_2, 10);
			vexMotorSet(kVexMotor_3, 10);
			vexMotorSet(kVexMotor_8, 10);
			vexMotorSet(kVexMotor_9, 10);
		} else {
			vexMotorSet(kVexMotor_2, 0);
			vexMotorSet(kVexMotor_3, 0);
			vexMotorSet(kVexMotor_8, 0);
			vexMotorSet(kVexMotor_9, 0);
		}

		/* CLAW */
		if(vexControllerGet(Btn5U)) {
			vexMotorSet(kVexMotor_1, 127);
			vexMotorSet(kVexMotor_10, 127);
		} else if (vexControllerGet(Btn5D)) {
			vexMotorSet(kVexMotor_1, -127);
			vexMotorSet(kVexMotor_10, -127);
		/* XMTR 2 */
		} else if (vexControllerGet(Btn5UXmtr2)) {
			vexMotorSet(kVexMotor_1, 127);
			vexMotorSet(kVexMotor_10, 127);
		} else if (vexControllerGet(Btn5DXmtr2)) {
			vexMotorSet(kVexMotor_1, -127);
			vexMotorSet(kVexMotor_10, -127);
		/* CLAW LOCK */
		} else if (clawLock == 1) {
			vexMotorSet(kVexMotor_1, -12);
			vexMotorSet(kVexMotor_10, -12);
		} else {
			vexMotorSet(kVexMotor_1, 0);
			vexMotorSet(kVexMotor_10, 0);
		}

		/* Check for IDWG resets */
		if(vexWatchdogResetFlagGet()) {
			vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, " Watchdog Reset ");
		}

		// Don't hog cpu
		vexSleep( 25 );
		}

	return (msg_t)0;
}