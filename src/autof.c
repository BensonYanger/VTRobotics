#include "vexstdinc.h"

#include "auto.h"
#include "autos.h"
#include "autof.h"

//360 ticks forward/back/left/right = 1/2 tile
//300 ticks turn for 45 degree

#define clawPot kVexAnalog_7
#define armPot kVexAnalog_5

#define driveBLPot kVexQuadEncoder_1
#define driveFRPot kVexQuadEncoder_2

void resetEnc(void) {
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
}

void stopDrive(void) {
    vexMotorSet(kVexMotor_4, 0);
    vexMotorSet(kVexMotor_5, 0);
    vexMotorSet(kVexMotor_6, 0);
    vexMotorSet(kVexMotor_7, 0);
}

//positive drive -> drive forward
void setDriveFB(int16_t drive) {
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_6, drive);
    vexMotorSet(kVexMotor_5, drive);
    vexMotorSet(kVexMotor_7, drive);
}

//positive drive with positive quad value -> goes forward
void driveFBfor(int16_t drive, int16_t quad)
{
    if(drive > 0) {
        while(vexEncoderGet(driveFRPot) < quad) {
            vexMotorSet(kVexMotor_4, drive);
            vexMotorSet(kVexMotor_6, drive);
            vexMotorSet(kVexMotor_5, drive);
            vexMotorSet(kVexMotor_7, drive);
            vexSleep(25);
        }
    }
    else if(drive < 0) {
        while(vexEncoderGet(driveFRPot) > quad) {
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

//negative drive -> drive right
void setDriveLR(int16_t drive) {
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_6, drive);
    vexMotorSet(kVexMotor_5, -drive);
    vexMotorSet(kVexMotor_7, -drive);
}

//negative drive, with a negative pot value -> drives right
void driveLRfor(int16_t drive, int16_t quad)
{
    if(drive > 0) {
        while(vexEncoderGet(driveFRPot) < quad){
            vexMotorSet(kVexMotor_4, drive);
            vexMotorSet(kVexMotor_6, drive);
            vexMotorSet(kVexMotor_5, -drive);
            vexMotorSet(kVexMotor_7, -drive);
            vexSleep(25);
        }
        return;
    }
    else if(drive < 0) {
        while(vexEncoderGet(driveFRPot) > quad){
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

//negative drive -> turn right
void setTurnLR(int16_t drive) {
    vexMotorSet(kVexMotor_4, -drive);
    vexMotorSet(kVexMotor_6, drive);
    vexMotorSet(kVexMotor_5, drive);
    vexMotorSet(kVexMotor_7, -drive);
}

//negative drive, with a negative pot -> turns right
void turnLRfor(int16_t drive, int16_t quad)
{
    if(drive > 0) {
        while(vexEncoderGet(driveFRPot) < quad){
            vexMotorSet(kVexMotor_4, -drive);
            vexMotorSet(kVexMotor_6, drive);
            vexMotorSet(kVexMotor_5, drive);
            vexMotorSet(kVexMotor_7, -drive);
            vexSleep(25);
        }
        return;
    }
    else if(drive < 0) {
        while(vexEncoderGet(driveFRPot) > quad){
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
//positive claw -> arm up
void setArm(int16_t lift) {
    vexMotorSet(kVexMotor_2, lift);
    vexMotorSet(kVexMotor_3, lift);
    vexMotorSet(kVexMotor_8, lift);
    vexMotorSet(kVexMotor_9, lift);
}

//4092 @ bottom, 1865 @ top
//positive claw value with negative pot -> arm goes up
void setArmfor(int16_t lift, int16_t pot)
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

void setClaw(int16_t claw) {
    vexMotorSet(kVexMotor_1, claw);
    vexMotorSet(kVexMotor_10, claw);
}

//3625 closed, 520 open
//negative claw with a greater pot value -> close claw
void setClawfor(int16_t claw, int16_t pot)
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