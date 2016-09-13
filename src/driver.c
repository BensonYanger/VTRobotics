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
		vexLcdPrintf( VEX_LCD_DISPLAY_2, VEX_LCD_LINE_2, "L %3d R %3d", vexMotorGet( kVexMotor_1 ), vexMotorGet( kVexMotor_10 ) );

		// motors
		vexMotorSet( kVexMotor_1, vexControllerGet( Ch3 ) );
		vexMotorSet( kVexMotor_2, vexControllerGet( Ch3 ) );
		vexMotorSet( kVexMotor_3, vexControllerGet( Ch3 ) );
		vexMotorSet( kVexMotor_4, vexControllerGet( Ch3 ) );
		vexMotorSet( kVexMotor_5, vexControllerGet( Ch3 ) );

		vexMotorSet( kVexMotor_6, vexControllerGet( Ch2 ) );
		vexMotorSet( kVexMotor_7, vexControllerGet( Ch2 ) );
		vexMotorSet( kVexMotor_8, vexControllerGet( Ch2 ) );
		vexMotorSet( kVexMotor_9, vexControllerGet( Ch2 ) );
		vexMotorSet( kVexMotor_10, vexControllerGet( Ch2 ) );

		// Don't hog cpu
		vexSleep( 25 );
		}

	return (msg_t)0;
}