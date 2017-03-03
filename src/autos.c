#include "vexstdinc.h"

#include "auto.h"
#include "autos.h"

#include "lift.h"

//a top 3440 bottom 1050
//c closed 3480 open (180) 1725 flip 540

//360 ticks forward/back/left/right = 1/2 tile
//300 ticks turn for 45 degree

#define clawPot kVexAnalog_7
#define armPot kVexAnalog_5

#define driveBLPot kVexQuadEncoder_1
#define driveFRPot kVexQuadEncoder_2

void stopDrive(void) {
    vexMotorSet(kVexMotor_4, 0);
    vexMotorSet(kVexMotor_5, 0);
    vexMotorSet(kVexMotor_6, 0);
    vexMotorSet(kVexMotor_7, 0);
}

void driveFB(int16_t drive, int16_t pot)
{
    if(drive > 0) {
        while(vexEncoderGet(driveFRPot) < pot) {
            vexMotorSet(kVexMotor_4, drive);
            vexMotorSet(kVexMotor_6, drive);
            vexMotorSet(kVexMotor_5, drive);
            vexMotorSet(kVexMotor_7, drive);
            vexSleep(25);
        }
    }
    else if(drive < 0) {
        while(vexEncoderGet(driveFRPot) > pot) {
            vexMotorSet(kVexMotor_4, drive);
            vexMotorSet(kVexMotor_6, drive);
            vexMotorSet(kVexMotor_5, drive);
            vexMotorSet(kVexMotor_7, drive);
            vexSleep(25);
        }
    }
    else {
        return;
    }
}

//right pot is negative, negative drive right
void driveLR(int16_t drive, int16_t pot)
{
    if(drive > 0) {
        while(vexEncoderGet(driveFRPot) < pot){
            vexMotorSet(kVexMotor_4, drive);
            vexMotorSet(kVexMotor_6, drive);
            vexMotorSet(kVexMotor_5, -drive);
            vexMotorSet(kVexMotor_7, -drive);
            vexSleep(25);
        }
        return;
    }
    else if(drive < 0) {
        while(vexEncoderGet(driveFRPot) > pot){
            vexMotorSet(kVexMotor_4, drive);
            vexMotorSet(kVexMotor_6, drive);
            vexMotorSet(kVexMotor_5, -drive);
            vexMotorSet(kVexMotor_7, -drive);
            vexSleep(25);
        }
        return;
    }
    else {
        return;
    }
}

//turn right negative, pot negative
void turnLR(int16_t drive, int16_t pot)
{
    if(drive > 0) {
        while(vexEncoderGet(driveFRPot) < pot){
            vexMotorSet(kVexMotor_4, -drive);
            vexMotorSet(kVexMotor_6, drive);
            vexMotorSet(kVexMotor_5, drive);
            vexMotorSet(kVexMotor_7, -drive);
            vexSleep(25);
        }
        return;
    }
    else if(drive < 0) {
        while(vexEncoderGet(driveFRPot) > pot){
            vexMotorSet(kVexMotor_4, -drive);
            vexMotorSet(kVexMotor_6, drive);
            vexMotorSet(kVexMotor_5, drive);
            vexMotorSet(kVexMotor_7, -drive);
            vexSleep(25);
        }
        return;
    }
    else {
        return;
    }
}

//4092 @ bottom, 1865 @ top
void setArm(int16_t lift, int16_t pot)
{
    if(lift > 0) {
        while(vexAdcGet(armPot) > pot) {
            vexMotorSet(kVexMotor_2, lift);
            vexMotorSet(kVexMotor_3, lift);
            vexMotorSet(kVexMotor_8, lift);
            vexMotorSet(kVexMotor_9, lift);
            vexSleep(25);
        }
    }
    else if(lift < 0) {
        while(vexAdcGet(armPot) < pot) {
            vexMotorSet(kVexMotor_2, lift);
            vexMotorSet(kVexMotor_3, lift);
            vexMotorSet(kVexMotor_8, lift);
            vexMotorSet(kVexMotor_9, lift);
            vexSleep(25);
        }
    }
    else {
        return;
    }
}

void stopArm(void) {
    vexMotorSet(kVexMotor_2, 0);
    vexMotorSet(kVexMotor_3, 0);
    vexMotorSet(kVexMotor_8, 0);
    vexMotorSet(kVexMotor_9, 0);
}

//3300 closed, 465 @ open
void setClaw(int16_t claw, int16_t pot)
{
    if(claw > 0) {
        while(vexAdcGet(clawPot) > pot) {
            vexMotorSet(kVexMotor_1, claw);
            vexMotorSet(kVexMotor_10, claw);
            vexSleep(25);
        }
    }
    else if(claw < 0) {
        while(vexAdcGet(clawPot) < pot) {
            vexMotorSet(kVexMotor_1, claw);
            vexMotorSet(kVexMotor_10, claw);
            vexSleep(25);
        }
    }
    else {
        return;
    }
}

void stopClaw(void) {
    vexMotorSet(kVexMotor_1, 0);
    vexMotorSet(kVexMotor_10, 0);
}

//-------------------------------

void startAuto(void)
{
    setArm(100, 3000);
    stopArm();
    vexSleep(250);
    setArm(-50, 3750);
    stopArm();
    vexSleep(250);
    setClaw(-60, 3300);
    stopClaw();
    vexSleep(250);
    setClaw(60, 2000);
    stopClaw();
    vexSleep(250);
}

void autoLeftCorner(void)
{

}

void autoRightCorner(void)
{

}

void autoLeftCube(void)
{

}

void autoRightCube(void)
{

}