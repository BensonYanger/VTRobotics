/*
 * fw.h
 *
 *  Created on: Jan 26, 2016
 *      Author: Benson
 */

#ifndef FW_H_
#define FW_H_

// Allow usage of this file in C++ programs
#ifdef __cplusplus
extern "C" {
#endif

#define FW1		4
#define FW2		5
#define FW3		6
#define FW4		7

short sgn(const float input);
void fwMotorSet(int value);
long fwMotorEncoderGet();
void fwVelocitySet(int velocity, float predicted_drive);
void fwCalculateSpeed();
void fwControlUpdateVelocityTbh();
void fwControl();
void fwMain();

// End C++ export structure
#ifdef __cplusplus
}
#endif

#endif /* FW_H_ */
