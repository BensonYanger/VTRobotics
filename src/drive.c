/*
 * drive.c
 *
 *  Created on: Jan 26, 2016
 *      Author: Benson
 */

#include "main.h"
#include "drive.h"

//TODO: MAKE IT BETTER
void driveTask() {

	int reversed = 0;

	while(1 & isEnabled(1)) {
		while(reversed == 0) {
			if(joystickGetAnalog(1, 3)) {
				motorSet(2, joystickGetAnalog(1, 3));
				motorSet(3, joystickGetAnalog(1, 3));
			}
			else {
				motorSet(2, 0);
				motorSet(3, 0);
			}

			if(joystickGetAnalog(1, 2)) {
				motorSet(8, -joystickGetAnalog(1, 2));
				motorSet(9, -joystickGetAnalog(1, 2));
			}
			else {
				motorSet(8, 0);
				motorSet(9, 0);
			}
		}

		while(reversed == 1) {
			if(joystickGetAnalog(1, 3)) {
				motorSet(2, -joystickGetAnalog(1, 3));
				motorSet(3, -joystickGetAnalog(1, 3));
			}
			else {
				motorSet(2, 0);
				motorSet(3, 0);
			}

			if(joystickGetAnalog(1, 2)) {
				motorSet(8, joystickGetAnalog(1, 2));
				motorSet(9, joystickGetAnalog(1, 2));
			}
			else {
				motorSet(8, 0);
				motorSet(9, 0);
			}
		}

		if(joystickGetDigital(1, 7, JOY_DOWN) == 1) {
			reversed = 0;
		}
		if(joystickGetDigital(1, 7, JOY_LEFT) == 1) {
			reversed = 1;
		}
			//partner intake
			if(joystickGetDigital (2, 5, JOY_UP) == 1) {
				motorSet(10, -127);
			}
			else if(joystickGetDigital (2, 5, JOY_DOWN) == 1) {
				motorSet(10, 127);
			}
			else if(joystickGetDigital (2, 7, JOY_UP) == 1) {
				motorSet(1, 127);
				motorSet(10, -127);
			}
			else if(joystickGetDigital (2, 7, JOY_RIGHT) == 1) {
				motorSet(1, -127);
				motorSet(10, 127);
			}
			else if(joystickGetDigital (2, 7, JOY_DOWN) == 1) {
				motorSet(1, -127);
			}
			else if(joystickGetDigital (2, 7, JOY_LEFT) == 1) {
				motorSet(1, 127);
			}

			delay(15);

	}
}
