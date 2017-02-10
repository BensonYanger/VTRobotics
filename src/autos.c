#include "vexstdinc.h"

#include "auto.h"
#include "autos.h"

#include "lift.h"

//a top 3440 bottom 1050
//c closed 3480 open (180) 1725 flip 540

//360 ticks forward/back/left/right = 1/2 tile
//300 ticks turn for 45 degree

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
    while(vexAdcGet(kVexAnalog_5) < 1725)
    {
        setClaw(-100);
        vexSleep(25);
    }
    setClaw(0);
    while(vexAdcGet(kVexAnalog_7) < 2000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(0);
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
}

void autoRight(void)
{
    //STAGE 1: KNOCK OFF STARS FROM FENCE
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) < 400)
    {
        driveLR(-60);
        vexSleep(20);
    }
    driveLR(0);
    setClaw(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -200)
    {
        driveFB(-60);
        vexSleep(20);
    }
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) < 150)
    {
        driveFB(60);
        vexSleep(20);
    }
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -850)
    {
        driveLR(60);
        vexSleep(20);
    }
    driveLR(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -300)
    {
        driveFB(-60);
        vexSleep(20);
    }
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) < 150)
    {
        driveFB(60);
        vexSleep(20);
    }
    //STAGE 2: GO FOR THE CUBE
    liftTarget = 850;
    driveFB(0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_3) < 40)
    {
        setArm(127);
        vexSleep(20);
    }
    setArm(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) < 165)
    {
        turnLR(50);
        vexSleep(20);
    }
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -200)
    {
        driveFB(-60);
        vexSleep(20);
    }
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    setClaw(127);
    vexSleep(1150);
    setClaw(0);
    while(vexEncoderGet(kVexQuadEncoder_3) > 10)
    {
        setArm(-127);
        vexSleep(20);
    }
    setArm(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) < 180)
    {
        driveFB(80);
        vexSleep(20);
    }
    driveFB(0);
    setClaw(-127);
    vexSleep(1250);
    setClaw(-10);
    while(vexEncoderGet(kVexQuadEncoder_3) < 40)
    {
        setArm(127);
        vexSleep(20);
    }
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -165)
    {
        turnLR(-50);
        vexSleep(20);
    }
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -300)
    {
        driveFB(-80);
        vexSleep(20);
    }
    //STAGE 3: DUMP CUBE
    driveFB(0);
    vexSleep(250);
    setClaw(127);
    vexSleep(250);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    setClaw(127);
    while(vexEncoderGet(kVexQuadEncoder_3) < 80)
    {
        setArm(127);
        vexSleep(20);
    }
    setArm(0);
    setClaw(127);
    vexSleep(1000);
    setArm(-127);
    vexSleep(1000);
    setClaw(-60);
    vexSleep(1500);
    setArm(0);
}

void autoLeftNoCube(void)
{
    //STAGE 1: KNOCK OFF STARS FROM FENCE
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    liftTarget = 2100;
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -350)
    {
        driveLR(60);
        vexSleep(20);
    }
    driveLR(0);
    setClaw(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -200)
    {
        driveFB(-60);
        vexSleep(20);
    }
    liftTarget = 2350;
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) < 150)
    {
        driveFB(60);
        vexSleep(20);
    }
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    liftTarget = 1900;
    while(vexEncoderGet(kVexQuadEncoder_1) < 850)
    {
        driveLR(-60);
        vexSleep(20);
    }
    driveLR(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -300)
    {
        driveFB(-60);
        vexSleep(20);
    }
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) < 150)
    {
        driveFB(60);
        vexSleep(20);
    }
    //STAGE 2: MOVE BACK TO OUR SIDE
    liftTarget = 850;
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -400)
    {
        driveLR(60);
        vexSleep(20);
    }
    driveLR(0);
    setClaw(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
}

void autoRightNoCube(void)
{
    //STAGE 1: KNOCK OFF STARS FROM FENCE
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    liftTarget = 2100;
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) < 350)
    {
        driveLR(-60);
        vexSleep(20);
    }
    driveLR(0);
    setClaw(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -200)
    {
        driveFB(-60);
        vexSleep(20);
    }
    liftTarget = 2350;
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) < 150)
    {
        driveFB(60);
        vexSleep(20);
    }
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    liftTarget = 1900;
    while(vexEncoderGet(kVexQuadEncoder_1) > -850)
    {
        driveLR(60);
        vexSleep(20);
    }
    driveLR(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) > -300)
    {
        driveFB(-60);
        vexSleep(20);
    }
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) < 150)
    {
        driveFB(60);
        vexSleep(20);
    }
    //STAGE 2: MOVE BACK TO OUR SIDE
    liftTarget = 850;
    driveFB(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
    while(vexEncoderGet(kVexQuadEncoder_1) < 400)
    {
        driveLR(-60);
        vexSleep(20);
    }
    driveLR(0);
    setClaw(0);
    vexSleep(100);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    vexSleep(100);
}