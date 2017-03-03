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

void turnLR(int16_t drive, int16_t pot)
{
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_6, -drive);
    vexMotorSet(kVexMotor_5, -drive);
    vexMotorSet(kVexMotor_7, drive);
}

//4092 @ bottom, 1865 @ top
void setArm(int16_t lift, int16_t pot)
{
    if(lift > 0) {
        while(vexAdcGet(armPot) < pot) {
            vexMotorSet(kVexMotor_2, lift);
            vexMotorSet(kVexMotor_3, lift);
            vexMotorSet(kVexMotor_8, lift);
            vexMotorSet(kVexMotor_9, lift);
            vexSleep(25);
        }
    }
    else if(lift < 0) {
        while(vexAdcGet(armPot) > pot) {
            vexMotorSet(kVexMotor_2, lift);
            vexMotorSet(kVexMotor_3, lift);
            vexMotorSet(kVexMotor_8, lift);
            vexMotorSet(kVexMotor_9, lift);
            vexSleep(25);
        }
    }
}

//3450 closed, 465 @ open
void setClaw(int16_t claw, int16_t pot)
{
    if(claw > 0) {
        while(vexAdcGet(clawPot) > pot) {

        }
    }
    else if(claw < 0) {
        while(vexAdcGet(clawPot) < pot) {

        }
    }
    vexMotorSet(kVexMotor_1, claw);
    vexMotorSet(kVexMotor_10, claw);
}

//-------------------------------

void startAuto(void)
{
    vexEncoderSet(driveFRPot, 0);
    vexEncoderSet(driveBLPot, 0);
    driveFB(60, 360);
    stopDrive();
    vexEncoderSet(driveFRPot, 0);
    vexEncoderSet(driveBLPot, 0);
    driveLR(60, 360);
    stopDrive();
    vexEncoderSet(driveFRPot, 0);
    vexEncoderSet(driveBLPot, 0);
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