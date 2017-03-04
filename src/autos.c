#include "vexstdinc.h"

#include "auto.h"
#include "autos.h"
#include "autof.h"

#include "lift.h"

//360 ticks forward/back/left/right = 1/2 tile
//300 ticks turn for 45 degree

#define clawPot kVexAnalog_7
#define armPot kVexAnalog_5

#define driveBLPot kVexQuadEncoder_1
#define driveFRPot kVexQuadEncoder_2

//-------------------------------

void startAuto(void)
{
    setClawfor(-90, 1500);
    setClaw(0);
    setArmfor(127, 3250);
    stopArm();
    setArmfor(-40, 4025);
    setArm(10);
    setClawfor(-60, 2300);
    setClaw(5);
    vexSleep(250);
    setClaw(-15);
    vexSleep(250);
}

void autoLeftCorner(void)
{
    resetEnc();
    driveFBfor(80, 720);
    stopDrive();
    vexSleep(250);
    resetEnc();
    setClawfor(-127, 3000);
    setClaw(-40);
    vexSleep(500);
    setArmfor(100, 3900);
    setArm(10);
    resetEnc();
    turnLRfor(80, 900);
    stopDrive();
    vexSleep(250);
    resetEnc();
    driveFBfor(-90, -300);
    setDriveFB(-50);
    setArmfor(127, 2250);
    setArm(0);
    setClawfor(127, 2000);
    setClaw(0);
    stopDrive();
    resetEnc();
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