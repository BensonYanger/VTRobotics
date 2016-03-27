/**
* File for autonomous code.
*
* This file should contain the user autonomous() function and any functions related to it.
*
* Copyright (c) 2011-2014, Purdue University ACM SIG BOTS. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* Neither the name of Purdue University ACM SIG BOTS nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source code may be obtained from http://sourceforge.net/projects/freertos/files/ or on request.
********************************************************************************/

#include "main.h"
#include "drive.h"
#include "lcdauto.h"
#include "fw.h"

/**
* Runs the user autonomous code.
*
* This function will be started in its own task with the default priority and stack size whenever the robot is enabled via the Field Management System or the VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart the task, not re-start it from where it left off.
*
* Code running in the autonomous task cannot access information from the VEX Joystick. However, the autonomous function can be invoked from another task if a VEX Competition Switch is not available, and it can access joystick information if called in this way.
*
* The autonomous task may exit, unlike operatorControl() which should never exit. If it does so, the robot will await a switch to another mode or disable/enable cycle.
*/

int target_speed;

int lineThreshold = 2000;

void drive(int motorPower) {
	motorSet(2, motorPower);
	motorSet(3, motorPower);
	motorSet(8, -motorPower);
	motorSet(9, -motorPower);
}

void turnLeft(int motorPower) {
	motorSet(2, -motorPower);
	motorSet(3, -motorPower);
	motorSet(8, -motorPower);
	motorSet(9, -motorPower);
}

void turnRight(int motorPower) {
	motorSet(2, motorPower);
	motorSet(3, motorPower);
	motorSet(8, motorPower);
	motorSet(9, motorPower);
}

void intake(int motorPower) {
	motorSet(1, motorPower);
	motorSet(10, -motorPower);
}

void defaultAuton() {
	fwVelocitySet(100, 0.70);
	target_speed = 100;
	drive(55);
	delay(1250);
	drive(0);
	delay(2000);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(2000);
	intake(0);
	drive(-80);
	fwVelocitySet(0, 0);
	target_speed = 0;
	delay(350);
	drive(0);
}

void halfCourtAuton() {
	fwVelocitySet(100, 0.70);
	target_speed = 100;
	drive(55);
	delay(1250);
	drive(0);
	delay(2000);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(1000);
	intake(0);
	drive(-80);
	fwVelocitySet(0, 0);
	target_speed = 0;
	delay(350);
	drive(0);
}

void barShotAuton() {
	fwVelocitySet(62, 0.40);
	target_speed = 62;
	drive(127);
	delay(1750);
	drive(32);
	delay(800);
	drive(0);
	delay(500);
	intake(127);
	delay(400);
	intake(0);
	delay(400);
	intake(127);
	delay(400);
	intake(0);
	delay(400);
	intake(127);
	delay(400);
	intake(0);
	delay(400);
	intake(127);
	delay(2000);
	intake(0);
	drive(-80);
	fwVelocitySet(0, 0);
	target_speed = 0;
	delay(1250);
	drive(0);
}

void barDelayed() {
	fwVelocitySet(62, 0.40);
	target_speed = 62;
	delay(2000);
	drive(127);
	delay(1750);
	drive(32);
	delay(800);
	drive(0);
	delay(500);
	intake(127);
	delay(400);
	intake(0);
	delay(400);
	intake(127);
	delay(400);
	intake(0);
	delay(400);
	intake(127);
	delay(400);
	intake(0);
	delay(400);
	intake(127);
	delay(2000);
	intake(0);
	drive(-80);
	fwVelocitySet(0, 0);
	target_speed = 0;
	delay(1250);
	drive(0);
}

void lmao() {
	drive(127);
	delay(1500);
	turnLeft(127);
	delay(4000);
	drive(0);
	delay(50);
	turnRight(4000);
	delay(5500);
}

void pSkills() {
	target_speed = 90;
	delay(1500);
	intake(127);
	delay(58500);
	intake(0);
	target_speed = 0;
}

//TODO: NOT TESTED
void testAuto1() {
	//set fw speed
	fwVelocitySet(100, 0.70);
	target_speed = 100;
	//drive forward
	drive(55);
	delay(1250);
	drive(0);
	//wait for fw
	delay(2000);
	//launch balls
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(1000);
	//stop ball launching
	intake(0);
	fwVelocitySet(0, 0);
	target_speed = 0;
	//turn for right side wall stack hopefully
	turnRight(40);
	delay(650);
	drive(0);
	delay(250);
	//drive backwards into wall stack
	drive(-40);
	intake(127);
	delay(1250);
	intake(0);
	//use roller ONLY
	motorSet(10, -127);
	delay(500);
	intake(0);
	drive(0);
	//move ball away from fw
	motorSet(1, -127);
	delay(350);
	intake(0);
	//set fw
	fwVelocitySet(100, 0.70);
	target_speed = 100;
	drive(40);
	delay(500);
	drive(0);
	//positioning turn
	turnLeft(40);
	delay(500);
	drive(0);
	//wait for fw
	delay(1750);
	//launch balls
	intake(127);
	delay(2000);
	//we done
	fwVelocitySet(0, 0);
	motorStopAll();
}

void testAuto2() {
	//set fw speed
	fwVelocitySet(100, 0.70);
	target_speed = 100;
	//drive forward
	drive(55);
	delay(1250);
	drive(0);
	//wait for fw
	delay(2000);
	//launch balls
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(1000);
	//stop ball launching
	intake(0);
	fwVelocitySet(0, 0);
	target_speed = 0;
	//turn for right side wall stack hopefully
	turnLeft(40);
	delay(650);
	drive(0);
	delay(250);
	//drive backwards into wall stack
	drive(-40);
	intake(127);
	delay(1250);
	intake(0);
	//use roller ONLY
	motorSet(10, -127);
	delay(500);
	intake(0);
	drive(0);
	//move ball away from fw
	motorSet(1, -127);
	delay(350);
	intake(0);
	//set fw
	fwVelocitySet(100, 0.70);
	target_speed = 100;
	drive(40);
	delay(500);
	drive(0);
	//positioning turn
	turnRight(40);
	delay(500);
	drive(0);
	//wait for fw
	delay(1750);
	//launch balls
	intake(127);
	delay(2000);
	//we done
	fwVelocitySet(0, 0);
	motorStopAll();
}

void testAuto3() {
	target_speed = 100;
	drive(55);
	delay(1250);
	drive(0);
	delay(2000);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(1000);
	intake(0);
	target_speed = 0;
	//turn for back side wall stack hopefully
	turnLeft(40);
	delay(650);
	drive(0);
	delay(250);
	drive(-40);
	intake(127);
	delay(1250);
	intake(0);
	motorSet(10, -127);
	delay(500);
	intake(0);
	drive(0);
	motorSet(1, -127);
	delay(350);
	intake(0);
	target_speed = 100;
	drive(40);
	delay(500);
	drive(0);
	turnRight(40);
	delay(650);
	drive(0);
	//wait for fw
	delay(1750);
	intake(127);
	delay(2000);
	motorStopAll();
}

void testAuto4() {
	target_speed = 100;
	drive(55);
	delay(1250);
	drive(0);
	delay(2000);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(350);
	intake(0);
	delay(650);
	intake(127);
	delay(1000);
	intake(0);
	target_speed = 0;
	//turn for back side wall stack hopefully
	turnRight(40);
	delay(650);
	drive(0);
	delay(250);
	drive(-40);
	intake(127);
	delay(1250);
	intake(0);
	motorSet(10, -127);
	delay(500);
	intake(0);
	drive(0);
	motorSet(1, -127);
	delay(350);
	intake(0);
	target_speed = 100;
	drive(40);
	delay(500);
	drive(0);
	turnLeft(40);
	delay(650);
	drive(0);
	//wait for fw
	delay(1750);
	intake(127);
	delay(2000);
	motorStopAll();
}

int auton = 0;

void autonomous() {

	switch(auton) {

		case 0:
			defaultAuton();
			break;
		case 1:
			halfCourtAuton();
			break;
		case 2:
			barShotAuton();
			break;
		case 3:
			barDelayed();
			break;
		case 4:
			lmao();
			break;
		case 5:
			pSkills();
			break;
		case 6:
			testAuto1();
			break;
		case 7:
			testAuto2();
			break;
		case 8:
			testAuto3();
			break;
		case 9:
			testAuto4();
			break;
	}

}
