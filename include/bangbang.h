/*
 * bangbang.h
 *
 *  Created on: Feb 18, 2016
 *      Author: Benson
 */

#ifndef INCLUDE_BANGBANG_H_
#define INCLUDE_BANGBANG_H_

// Allow usage of this file in C++ programs
#ifdef __cplusplus
extern "C" {
#endif

#define FW1		4
#define FW2		5
#define FW3		6
#define FW4		7

// encoder counts per revolution depending on motor
#define MOTOR_269           240.448
#define MOTOR_393R          261.333
#define MOTOR_393S          392
#define MOTOR_393T          627.2
#define MOTOR_QUAD          360.0

extern int target_speed;

long IMEGet();
void fwMotorSet(int motorPower);
void fwRpmCalc();
void bbControl();
void bbLcd();

// End C++ export structure
#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_BANGBANG_H_ */
