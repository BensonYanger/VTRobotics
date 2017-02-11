#include "vexstdinc.h"

#include "auto.h"
#include "autos.h"

#include "lift.h"

//a top 3440 bottom 1050
//c closed 3480 open (180) 1725 flip 540

//360 ticks forward/back/left/right = 1/2 tile
//300 ticks turn for 45 degree

int16_t clawPot = (int)kVexAnalog_7;
int16_t armPot = (int)kVexAnalog_5;

void driveFB(int16_t drive)
{
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_6, drive);
    vexMotorSet(kVexMotor_5, drive);
    vexMotorSet(kVexMotor_7, drive);
}

void driveLR(int16_t drive)
{
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_6, drive);
    vexMotorSet(kVexMotor_5, -drive);
    vexMotorSet(kVexMotor_7, -drive);
}

void turnLR(int16_t drive)
{
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_6, -drive);

    vexMotorSet(kVexMotor_5, -drive);
    vexMotorSet(kVexMotor_7, drive);
}

void setArm(int16_t lift)
{
    vexMotorSet(kVexMotor_2, lift);
    vexMotorSet(kVexMotor_3, lift);
    vexMotorSet(kVexMotor_8, lift);
    vexMotorSet(kVexMotor_9, lift);
}

void setClaw(int16_t claw)
{
    vexMotorSet(kVexMotor_1, claw);
    vexMotorSet(kVexMotor_10, claw);
}

//-------------------------------

void startAuto(void)
{
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    while(vexAdcGet(clawPot) < 1725)
    {
        setClaw(-80);
        vexSleep(25);
    }
    setClaw(0);
    while(vexAdcGet(armPot) < 2000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(10);
}

void autoLeft(void)
{
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    while(vexEncoderGet(kVexQuadEncoder_2) < 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    while(vexEncoderGet(kVexQuadEncoder_2) < 900)
    {
        turnLR(80);
        vexSleep(25);
    }
    turnLR(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
}

void autoRight(void)
{
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    while(vexEncoderGet(kVexQuadEncoder_2) < 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    while(vexEncoderGet(kVexQuadEncoder_2) > -900)
    {
        turnLR(-80);
        vexSleep(25);
    }
    turnLR(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
}

void autoLeftNoCube(void)
{
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
}

void autoRightNoCube(void)
{
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
}