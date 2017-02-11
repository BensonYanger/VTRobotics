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
    //preload
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //close claw and lock
    while(vexAdcGet(clawPot) <= 3240)
    {
        setClaw(-127);
        vexSleep(25);
    }
    setClaw(-15);
    vexSleep(250);
    //lift arm slightly and lock
    while(vexAdcGet(armPot) < 2000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(15);
}

void autoLeftCorner(void)
{
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //clear starting tile
    while(vexEncoderGet(driveFRPot) <= 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //turn to left corner
    while(vexEncoderGet(driveFRPot) <= 550)
    {
        turnLR(-70);
        vexSleep(25);
    }
    turnLR(0);
    //bring arm down
    while(vexAdcGet(armPot) > 1100)
    {
        setArm(-100);
        vexSleep(25);
    }
    setArm(0);
    //release preload
    if(vexAdcGet(clawPot) >= 1725)
    {
        while(vexAdcGet(clawPot) >= 1725)
        {
            setClaw(80);
            vexSleep(25);
        }
    }
    else if(vexAdcGet(clawPot) < 1725)
    {
        while(vexAdcGet(clawPot) < 1725)
        {
            setClaw(-80);
            vexSleep(25);
        }
    }
    setClaw(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //drive to left corner star
    while(vexEncoderGet(driveFRPot) <= 150)
    {
        driveFB(70);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //grab left corner star
    while(vexAdcGet(clawPot) < 3400)
    {
        setClaw(-127);
        vexSleep(25);
    }
    setClaw(-15);
    //lift arm up before movement
    while(vexAdcGet(armPot) < 2000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(15);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //back up
    while(vexEncoderGet(driveFRPot) >= -360)
    {
        driveFB(-80);
        vexSleep(25);
    }
    driveFB(0);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //turn to fence
    while(vexEncoderGet(driveFRPot) <= 300)
    {
        turnLR(-70);
        vexSleep(25);
    }
    turnLR(0);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //back up to fence
    while(vexEncoderGet(driveFRPot) > -1000)
    {
        driveFB(-80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //lift arm
    while(vexAdcGet(armPot) < 3000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(96);
    //open claw and dump
    while(vexAdcGet(clawPot) > 2000)
    {
        setClaw(127);
        vexSleep(25);
    }
    setClaw(0);
    setArm(0);
    //clear fence
    while(vexEncoderGet(driveFRPot) <= 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //lower arm
    while(vexAdcGet(armPot) > 1200)
    {
        setArm(-127);
        vexSleep(25);
    }
    setArm(0);
    //open claw to 180
    if(vexAdcGet(clawPot) >= 1725)
    {
        while(vexAdcGet(clawPot) >= 1725)
        {
            setClaw(80);
            vexSleep(25);
        }
    }
    else if(vexAdcGet(clawPot) < 1725)
    {
        while(vexAdcGet(clawPot) < 1725)
        {
            setClaw(-80);
            vexSleep(25);
        }
    }
    setClaw(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
}

void autoRightCorner(void)
{
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //clear starting tile
    while(vexEncoderGet(driveFRPot) <= 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //turn to right corner
    while(vexEncoderGet(driveFRPot) >= -550)
    {
        turnLR(70);
        vexSleep(25);
    }
    turnLR(0);
    //bring down arm
    while(vexAdcGet(armPot) > 1100)
    {
        setArm(-100);
        vexSleep(25);
    }
    setArm(0);
    //release preload
    if(vexAdcGet(clawPot) >= 1725)
    {
        while(vexAdcGet(clawPot) >= 1725)
        {
            setClaw(80);
            vexSleep(25);
        }
    }
    else if(vexAdcGet(clawPot) < 1725)
    {
        while(vexAdcGet(clawPot) < 1725)
        {
            setClaw(-80);
            vexSleep(25);
        }
    }
    setClaw(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //drive to right corner star
    while(vexEncoderGet(driveFRPot) <= 150)
    {
        driveFB(70);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //grab right corner star
    while(vexAdcGet(clawPot) < 3400)
    {
        setClaw(-127);
        vexSleep(25);
    }
    setClaw(-15);
    //lift arm before movement
    while(vexAdcGet(armPot) < 2000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(15);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //back up
    while(vexEncoderGet(driveFRPot) >= -360)
    {
        driveFB(-80);
        vexSleep(25);
    }
    driveFB(0);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //turn to fence
    while(vexEncoderGet(driveFRPot) >= -300)
    {
        turnLR(70);
        vexSleep(25);
    }
    turnLR(0);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //back up to fence
    while(vexEncoderGet(driveFRPot) > -1000)
    {
        driveFB(-80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //lift arm
    while(vexAdcGet(armPot) < 3000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(96);
    //open claw and dump
    while(vexAdcGet(clawPot) > 2000)
    {
        setClaw(127);
        vexSleep(25);
    }
    setClaw(0);
    setArm(0);
    //clear fence
    while(vexEncoderGet(driveFRPot) <= 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //lower arm
    while(vexAdcGet(armPot) > 1200)
    {
        setArm(-127);
        vexSleep(25);
    }
    setArm(0);
    //open claw to 180
    if(vexAdcGet(clawPot) >= 1725)
    {
        while(vexAdcGet(clawPot) >= 1725)
        {
            setClaw(80);
            vexSleep(25);
        }
    }
    else if(vexAdcGet(clawPot) < 1725)
    {
        while(vexAdcGet(clawPot) < 1725)
        {
            setClaw(-80);
            vexSleep(25);
        }
    }
    setClaw(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
}

void autoLeftCube(void)
{
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //clear starting tile
    while(vexEncoderGet(driveFRPot) <= 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //drive 1/2 to cube
    while(vexEncoderGet(driveFRPot) < 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //bring arm down
    while(vexAdcGet(armPot) > 1100)
    {
        setArm(-100);
        vexSleep(25);
    }
    setArm(0);
    //release preload
    while(vexAdcGet(clawPot) > 1725)
    {
        setClaw(80);
        vexSleep(25);
    }
    setClaw(0);
    //drive 2/2 to cube
    while(vexEncoderGet(driveFRPot) < 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //grab cube and lock
    while(vexAdcGet(clawPot) <= 3240)
    {
        setClaw(-127);
        vexSleep(25);
    }
    setClaw(-15);
    vexSleep(250);
    //lift arm slightly and lock
    while(vexAdcGet(armPot) < 2000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(15);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //turn towards fence
    while(vexEncoderGet(driveFRPot) >= -600)
    {
        turnLR(-80);
        vexSleep(25);
    }
    turnLR(0);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //back up to fence
    while(vexEncoderGet(driveFRPot) > -1000)
    {
        driveFB(-80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //lift arm
    while(vexAdcGet(armPot) < 3000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(96);
    //open claw and dump
    while(vexAdcGet(clawPot) > 1650)
    {
        setClaw(127);
        vexSleep(25);
    }
    setClaw(0);
    setArm(0);
    //bring arm down
    while(vexAdcGet(armPot) > 1150)
    {
        setArm(-100);
        vexSleep(25);
    }
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //drive to 3 star
    while(vexEncoderGet(driveFRPot) <= 1300)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //close claw and lock
    while(vexAdcGet(clawPot) <= 3240)
    {
        setClaw(-127);
        vexSleep(25);
    }
    setClaw(-15);
    vexSleep(250);
    //lift arm slightly and lock
    while(vexAdcGet(armPot) < 2000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(15);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //back up to fence
    while(vexEncoderGet(driveFRPot) >= -1300)
    {
        driveFB(-80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //lift arm
    while(vexAdcGet(armPot) < 3000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(96);
    //open claw and dump
    while(vexAdcGet(clawPot) > 1650)
    {
        setClaw(127);
        vexSleep(25);
    }
    setClaw(0);
    setArm(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //clear fence
    while(vexEncoderGet(driveFRPot) <= 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //lower arm
    while(vexAdcGet(armPot) > 1200)
    {
        setArm(-127);
        vexSleep(25);
    }
    setArm(0);
    //open claw to 180
    if(vexAdcGet(clawPot) >= 1725)
    {
        while(vexAdcGet(clawPot) >= 1725)
        {
            setClaw(80);
            vexSleep(25);
        }
    }
    else if(vexAdcGet(clawPot) < 1725)
    {
        while(vexAdcGet(clawPot) < 1725)
        {
            setClaw(-80);
            vexSleep(25);
        }
    }
    setClaw(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
}

void autoRightCube(void)
{
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //clear starting tile
    while(vexEncoderGet(driveFRPot) <= 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //drive 1/2 to cube
    while(vexEncoderGet(driveFRPot) < 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //bring arm down
    while(vexAdcGet(armPot) > 1100)
    {
        setArm(-100);
        vexSleep(25);
    }
    setArm(0);
    //release preload
    while(vexAdcGet(clawPot) > 1725)
    {
        setClaw(80);
        vexSleep(25);
    }
    setClaw(0);
    //drive 2/2 to cube
    while(vexEncoderGet(driveFRPot) < 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //grab cube and lock
    while(vexAdcGet(clawPot) <= 3240)
    {
        setClaw(-127);
        vexSleep(25);
    }
    setClaw(-15);
    vexSleep(250);
    //lift arm slightly and lock
    while(vexAdcGet(armPot) < 2000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(15);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //turn towards fence
    while(vexEncoderGet(driveFRPot) <= 600)
    {
        turnLR(80);
        vexSleep(25);
    }
    turnLR(0);
    vexSleep(500);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //back up to fence
    while(vexEncoderGet(driveFRPot) > -1000)
    {
        driveFB(-80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //lift arm
    while(vexAdcGet(armPot) < 3000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(96);
    //open claw and dump
    while(vexAdcGet(clawPot) > 1650)
    {
        setClaw(127);
        vexSleep(25);
    }
    setClaw(0);
    setArm(0);
    //bring arm down
    while(vexAdcGet(armPot) > 1150)
    {
        setArm(-100);
        vexSleep(25);
    }
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //drive to 3 star
    while(vexEncoderGet(driveFRPot) <= 1300)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //close claw and lock
    while(vexAdcGet(clawPot) <= 3240)
    {
        setClaw(-127);
        vexSleep(25);
    }
    setClaw(-15);
    vexSleep(250);
    //lift arm slightly and lock
    while(vexAdcGet(armPot) < 2000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(15);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //back up to fence
    while(vexEncoderGet(driveFRPot) >= -1300)
    {
        driveFB(-80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //lift arm
    while(vexAdcGet(armPot) < 3000)
    {
        setArm(127);
        vexSleep(25);
    }
    setArm(96);
    //open claw and dump
    while(vexAdcGet(clawPot) > 1650)
    {
        setClaw(127);
        vexSleep(25);
    }
    setClaw(0);
    setArm(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //clear fence
    while(vexEncoderGet(driveFRPot) <= 360)
    {
        driveFB(80);
        vexSleep(25);
    }
    driveFB(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
    //lower arm
    while(vexAdcGet(armPot) > 1200)
    {
        setArm(-127);
        vexSleep(25);
    }
    setArm(0);
    //open claw to 180
    if(vexAdcGet(clawPot) >= 1725)
    {
        while(vexAdcGet(clawPot) >= 1725)
        {
            setClaw(80);
            vexSleep(25);
        }
    }
    else if(vexAdcGet(clawPot) < 1725)
    {
        while(vexAdcGet(clawPot) < 1725)
        {
            setClaw(-80);
            vexSleep(25);
        }
    }
    setClaw(0);
    vexEncoderSet(kVexQuadEncoder_1, 0);
    vexEncoderSet(kVexQuadEncoder_2, 0);
}