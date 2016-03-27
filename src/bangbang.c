/*
 * bangbang.c
 *
 *  Created on: Feb 18, 2016
 *      Author: Benson
 */

#include "main.h"
#include "bangbang.h"
#include "lcdauto.h"

	//IME
	float		ticks_per_rev;
	int 		enc_current;
	int 		enc_last;

	//vel/time (RPM)
	int		    v_current;
	long		v_time;
	int			target_speed;

long fwEncoderGet()
{
	long fw_encoder;
	fw_encoder = encoderGet(flywheel);
	return fw_encoder;
}

long IMEGet()
{
    long ime_count0;
    imeGet (0, &ime_count0);
    return abs(ime_count0);
}

long IMEGet2() {
	long ime_count1;
	imeGet (1, &ime_count1);
	return abs(ime_count1);
}

void bbMotorSet(int motorPower) {
    motorSet(FW1, motorPower);
    motorSet(FW2, -motorPower);
    motorSet(FW3, motorPower);
    motorSet(FW4, -motorPower);
}

void fwRpmCalc() {
	int     delta_ms;
	int     delta_enc;
	ticks_per_rev = MOTOR_QUAD;

    // Get current encoder value
    enc_current = fwEncoderGet();

	delta_ms   = millis() - v_time;
	v_time = millis();

	// Change in encoder count
	delta_enc = (enc_current - enc_last);

	// save last position
	enc_last = enc_current;

	v_current = (1000.0 / delta_ms) * delta_enc * 60.0 / ticks_per_rev / 5;
}

void bbControl() {

	char lcdStr[32];

	while(1) {

		fwRpmCalc();

		if(target_speed > 60) {
			if(v_current < target_speed) {
				bbMotorSet(127);
			}
			else if(v_current >= target_speed) {
				bbMotorSet(20);
			}
		}

		if(target_speed <= 60) {
			if(v_current < target_speed) {
				bbMotorSet(127);
			}
			else if(v_current >= target_speed) {
				bbMotorSet(5);
			}
		}

		if(target_speed == 0) {
			bbMotorSet(0);
		}

		if (target_speed == 0) {
			digitalWrite(10, HIGH);
			digitalWrite(11, HIGH);
			digitalWrite(12, HIGH);
		}
		else if (target_speed > v_current) {
			digitalWrite(10, LOW);
			digitalWrite(11, LOW);
			digitalWrite(12, HIGH);
		}
		else if (target_speed < v_current) {
			digitalWrite(10, HIGH);
			digitalWrite(11, LOW);
			digitalWrite(12, LOW);
		}

		// Different speeds set by buttons
		if(joystickGetDigital(1, 7, JOY_DOWN) == 1)
			target_speed = 125;
		if(joystickGetDigital(1, 6, JOY_UP) == 1 )
			target_speed = 100;
		if(joystickGetDigital(1, 6, JOY_DOWN) == 1 )
			target_speed = 90;
		if(joystickGetDigital(1, 8, JOY_UP) == 1 )
			target_speed = 80;
		if(joystickGetDigital(1, 8, JOY_RIGHT) == 1 )
			target_speed = 70;
		if(joystickGetDigital(1, 8, JOY_DOWN) == 1 )
			target_speed = 62;
		if(joystickGetDigital(1, 8, JOY_LEFT) == 1 )
			target_speed = 0;

		//LCD
		sprintf(lcdStr, "TAR CUR BATT");
		lcdSetText(uart2, 1, lcdStr);
		sprintf(lcdStr, "%3d %3d %5.2fV", target_speed, v_current, powerLevelMain()/1000.0);
		lcdSetText(uart2, 2, lcdStr);
		delay(15);

		delay(20);
	}
}
