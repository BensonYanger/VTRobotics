/*
 * lcdauto.c
 *
 *  Created on: Feb 15, 2016
 *      Author: Benson
 */

#include "main.h"
#include "lcdauto.h"

void lcdAuto() {
		//Leave this value alone
		int lcdScreenMin = 1;
		//This keeps track of which program you want to run
		int lcdScreen = 1;
		//Change this value to be the maximum number of programs you want on the robot
		int lcdScreenMax = 8;

		while (!isEnabled()) {
			if (lcdReadButtons(uart1 ) == 1) { //Scrolls to the left
				if (lcdScreenMin == lcdScreen) {
					lcdScreen = lcdScreenMax;
					delay(250);
				} else {
					lcdScreen --;
					delay(250);
				}
			}
			if (lcdReadButtons(uart1 ) == 4) { //Scrolls to the right
				if (lcdScreenMax == lcdScreen) {
					lcdScreen = lcdScreenMin;
					delay(250);
				} else {
					lcdScreen++;
					delay(250);
				}
			}
			if (lcdScreen == 1 && auton != 1) {
				lcdPrint(uart1, 1, "       1        "); //Name the first program here
				lcdPrint(uart1, 2, "   Half Court   "); //Name the first program here
				if (lcdReadButtons(uart1 ) == 2) {
					auton = lcdScreen; //Sets the Program to the one on-screen
					lcdPrint(uart1, 1, "Autonomous Has");
					lcdPrint(uart1, 2, "Been Selected!");
					delay(1000);
				}
			} else if (lcdScreen == 1 && auton == 1) {
				lcdPrint(uart1, 1, "      [1]       "); //We use brackets to mark which program we have chosen
				lcdPrint(uart1, 2, "   Half Court   "); //So that while we're scrolling, we can have one marked
			} else if (lcdScreen == 2 && auton != 2) {
				lcdPrint(uart1, 1, "       2        "); //Name the second program here
				lcdPrint(uart1, 2, "    Bar Shot    "); //Name the second program here
				if (lcdReadButtons(uart1 ) == 2) {
					auton = lcdScreen; //Sets the Program to the one on-screen
					lcdPrint(uart1, 1, "Autonomous Has");
					lcdPrint(uart1, 2, "Been Selected!");
					delay(1000);
				}
			} else if (lcdScreen == 2 && auton == 2) {
				lcdPrint(uart1, 1, "      [2]       "); //We use brackets to mark which program we have chosen
				lcdPrint(uart1, 2, "    Bar Shot    "); //So that while we're scrolling, we can have one marked
			} else if (lcdScreen == 3 && auton != 3) {
				lcdPrint(uart1, 1, "       3        "); //Name the third program here
				lcdPrint(uart1, 2, "   Delayed Bar  "); //Name the third program here
				if (lcdReadButtons(uart1 ) == 2) {
					auton = lcdScreen; //Sets the Program to the one on-screen
					lcdPrint(uart1, 1, "Autonomous Has");
					lcdPrint(uart1, 2, "Been Selected!");
					delay(1000);
				}
			} else if (lcdScreen == 3 && auton == 3) {
				lcdPrint(uart1, 1, "      [3]       "); //We use brackets to mark which program we have chosen
				lcdPrint(uart1, 2, "   Delayed Bar  "); //So that while we're scrolling, we can have one marked
			} else if (lcdScreen == 4 && auton != 4) {
				lcdPrint(uart1, 1, "       4        "); //Name the fourth program here
				lcdPrint(uart1, 2, "   lmao gotem   "); //Name the fourth program here
				if (lcdReadButtons(uart1 ) == 2) {
					auton = lcdScreen; //Sets the Program to the one on-screen
					lcdPrint(uart1, 1, "Autonomous Has");
					lcdPrint(uart1, 2, "Been Selected!");
					delay(1000);
				}
			} else if (lcdScreen == 4 && auton == 4) {
				lcdPrint(uart1, 1, "      [4]       "); //We use brackets to mark which program we have chosen
				lcdPrint(uart1, 2, "   lmao gotem   "); //So that while we're scrolling, we can have one marked
			} else if (lcdScreen == 5 && auton != 5) {
				lcdPrint(uart1, 1, "       5        "); //Name the fifth program here
				lcdPrint(uart1, 2, " Program Skills "); //Name the fifth program here
				if (lcdReadButtons(uart1 ) == 2) {
					auton = lcdScreen; //Sets the Program to the one on-screen
					lcdPrint(uart1, 1, "Autonomous Has");
					lcdPrint(uart1, 2, "Been Selected!");
					delay(1000);
				}
			} else if (lcdScreen == 5 && auton == 5) {
				lcdPrint(uart1, 1, "      [5]       "); //We use brackets to mark which program we have chosen
				lcdPrint(uart1, 2, " Program Skills "); //So that while we're scrolling, we can have one marked
			} else if (lcdScreen == 6 && auton != 6) {
				lcdPrint(uart1, 1, "       6        "); //Name the sixth program here
				lcdPrint(uart1, 2, "BLUE Outer TEST "); //Name the sixth program here
				if (lcdReadButtons(uart1 ) == 2) {
					auton = lcdScreen; //Sets the Program to the one on-screen
					lcdPrint(uart1, 1, "Autonomous Has");
					lcdPrint(uart1, 2, "Been Selected!");
					delay(1000);
				}
			} else if (lcdScreen == 6 && auton == 6) {
				lcdPrint(uart1, 1, "      [6]       "); //We use brackets to mark which program we have chosen
				lcdPrint(uart1, 2, "BLUE Outer TEST "); //So that while we're scrolling, we can have one marked
			} else if (lcdScreen == 7 && auton != 7) {
				lcdPrint(uart1, 1, "       7        "); //Name the seventh program here
				lcdPrint(uart1, 2, " RED Outer TEST "); //Name the seventh program here
				if (lcdReadButtons(uart1 ) == 2) {
					auton = lcdScreen; //Sets the Program to the one on-screen
					lcdPrint(uart1, 1, "Autonomous Has");
					lcdPrint(uart1, 2, "Been Selected!");
					delay(1000);
				}
			} else if (lcdScreen == 7 && auton == 7) {
				lcdPrint(uart1, 1, "      [7]       "); //We use brackets to mark which program we have chosen
				lcdPrint(uart1, 2, " RED Outer TEST "); //So that while we're scrolling, we can have one marked
			} else if (lcdScreen == 8 && auton != 8) {
				lcdPrint(uart1, 1, "       8        "); //Name the eighth program here
				lcdPrint(uart1, 2, "BLUE Inner TEST "); //Name the eighth program here
				if (lcdReadButtons(uart1 ) == 2) {
					auton = lcdScreen; //Sets the Program to the one on-screen
					lcdPrint(uart1, 1, "Autonomous Has");
					lcdPrint(uart1, 2, "Been Selected!");
					delay(1000);
				}
			} else if (lcdScreen == 8 && auton == 8) {
				lcdPrint(uart1, 1, "      [8]       "); //We use brackets to mark which program we have chosen
				lcdPrint(uart1, 2, "BLUE Inner TEST "); //So that while we're scrolling, we can have one marked
			} else if (lcdScreen == 9 && auton != 9) {
				lcdPrint(uart1, 1, "       9        "); //Name the ninth program here
				lcdPrint(uart1, 2, " RED Inner TEST "); //Name the ninth program here
				if (lcdReadButtons(uart1 ) == 2) {
					auton = lcdScreen; //Sets the Program to the one on-screen
					lcdPrint(uart1, 1, "Autonomous Has");
					lcdPrint(uart1, 2, "Been Selected!");
					delay(1000);

			} else if (lcdScreen == 9 && auton == 9) {
				lcdPrint(uart1, 1, "      [9]       "); //We use brackets to mark which program we have chosen
				lcdPrint(uart1, 2, " RED Inner TEST "); //So that while we're scrolling, we can have one marked
			}
			delay(20);
			}
		}
}

void lcdSensor() {
	int lcdStr[32];
	while(1) {
		sprintf(lcdStr, "%4d %4d %5d", encoderGet(driveL), encoderGet(driveR) ,encoderGet(flywheel));
		lcdSetText(uart2, 1, lcdStr);
		sprintf(lcdStr, "%5d %5d %5d", analogRead(2), analogRead(3), analogRead(4));
		lcdSetText(uart2, 2, lcdStr);
		delay(15);
	}
}
