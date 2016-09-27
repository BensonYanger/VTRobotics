#include "vexstdinc.h"

#include "driver.h"

/*-----------------------------------------------------------------------------*/
/** @brief      Driver control                                                 */
/*-----------------------------------------------------------------------------*/
/** @details
 *  This thread is started when the driver control period is started
 */

msg_t
vexOperator( void *arg )
{
	int16_t		blinkr1 = 0;
	int16_t		blinky1 = 0;
	int16_t		blinkg1 = 0;

	int16_t		blinkr2 = 0;
	int16_t		blinky2 = 0;
	int16_t		blinkg2 = 0;

	(void)arg;

	// Must call this
	vexTaskRegister("operator");

	// Run until asked to terminate
	while(!chThdShouldTerminate())
		{
		// flash led/digi out
		vexDigitalPinSet( kVexDigital_1, (blinkr1++ >> 2) & 1);
		vexDigitalPinSet( kVexDigital_2, (blinky1++ >> 2) & 1);
		vexDigitalPinSet( kVexDigital_3, (blinkg1++ >> 2) & 1);

		vexDigitalPinSet( kVexDigital_10, (blinkr2++ >> 2) & 1);
		vexDigitalPinSet( kVexDigital_11, (blinky2++ >> 2) & 1);
		vexDigitalPinSet( kVexDigital_12, (blinkg2++ >> 2) & 1);

		// status on LCD of encoder and sonar
		vexLcdPrintf( VEX_LCD_DISPLAY_2, VEX_LCD_LINE_1, "%4.2fV   %8.1f", vexSpiGetMainBattery() / 1000.0, chTimeNow() / 1000.0 );
		vexLcdPrintf( VEX_LCD_DISPLAY_2, VEX_LCD_LINE_2, "L %3d R %3d", vexMotorGet( kVexMotor_1 ), vexMotorGet( kVexMotor_10 ) );

		vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "POT %4d", vexAdcGet(1));
		vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "");

		// motors
		vexMotorSet( kVexMotor_4, -vexControllerGet( Ch3 ) );
		vexMotorSet( kVexMotor_5, -vexControllerGet( Ch3 ) );

		vexMotorSet( kVexMotor_6, -vexControllerGet( Ch2 ) );
		vexMotorSet( kVexMotor_7, -vexControllerGet( Ch2 ) );

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
		} else if(vexControllerGet(Btn5U)) {
			vexMotorSet(kVexMotor_2, 60);
			vexMotorSet(kVexMotor_3, 60);
			vexMotorSet(kVexMotor_8, 60);
			vexMotorSet(kVexMotor_9, 60);
		} else if (vexControllerGet(Btn5D)) {
			vexMotorSet(kVexMotor_2, -60);
			vexMotorSet(kVexMotor_3, -60);
			vexMotorSet(kVexMotor_8, -60);
			vexMotorSet(kVexMotor_9, -60);
		} else {
			vexMotorSet(kVexMotor_2, 0);
			vexMotorSet(kVexMotor_3, 0);
			vexMotorSet(kVexMotor_8, 0);
			vexMotorSet(kVexMotor_9, 0);
		}

		// Don't hog cpu
		vexSleep( 25 );
		}

	return (msg_t)0;
}