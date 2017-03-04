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
    setClawfor(-60, 1700);
    setClaw(5);
    vexSleep(250);
}

void autoLeftCubeMid(void)
{
    resetEnc();
    driveFBfor(60, 220);
    stopDrive();
    setArmfor(-50, 4035);
    setArm(10);
    driveFBfor(100, 900);
    stopDrive();
    vexSleep(250);
    resetEnc();
    setClawfor(-127, 3000);
    setClaw(-40);
    vexSleep(300);
    setArmfor(100, 3300);
    setArm(10);
    resetEnc();
    driveFBfor(70, 100);
    stopDrive();
    vexSleep(250);
    resetEnc();
    turnLRfor(-80, -550);
    stopDrive();
    vexSleep(250);
    resetEnc();
    driveFBfor(-90, -300);
    setDriveFB(-45);
    setArmfor(127, 2150);
    setArm(0);
    stopDrive();
    setClawfor(127, 1900);
    setClaw(0);
    resetEnc();
    setClawfor(-50, 1600);
    setArmfor(-70, 3900);
    setArm(15);
    driveFBfor(80, 300);
    stopDrive();
    resetEnc();
    vexSleep(250);
    resetEnc();
    driveFBfor(80, 650);
    stopDrive();
    setClawfor(-127, 3000);
    setClaw(-50);
    vexSleep(250);
    setArmfor(70, 3000);
    resetEnc();
    driveFBfor(-110, -600);
    setDriveFB(-45);
    setArmfor(65, 2150);
    setArm(0);
    stopDrive();
    vexSleep(250);
    setClawfor(127, 1900);
    setClaw(0);
    resetEnc();
    setClawfor(-50, 1600);
    setArmfor(-70, 3900);
    setArm(15);
}

void autoRightCubeMid(void)
{
    resetEnc();
    driveFBfor(60, 220);
    stopDrive();
    setArmfor(-50, 4035);
    setArm(10);
    driveFBfor(100, 900);
    stopDrive();
    vexSleep(250);
    resetEnc();
    setClawfor(-127, 3000);
    setClaw(-40);
    vexSleep(300);
    setArmfor(100, 3300);
    setArm(10);
    resetEnc();
    driveFBfor(70, 100);
    stopDrive();
    vexSleep(250);
    resetEnc();
    turnLRfor(80, 550);
    stopDrive();
    vexSleep(250);
    resetEnc();
    driveFBfor(-90, -300);
    setDriveFB(-45);
    setArmfor(127, 2150);
    setArm(0);
    stopDrive();
    setClawfor(127, 1900);
    setClaw(0);
    resetEnc();
    setClawfor(-50, 1600);
    setArmfor(-70, 3900);
    setArm(15);
    driveFBfor(80, 300);
    stopDrive();
    resetEnc();
    vexSleep(250);
    resetEnc();
    driveFBfor(80, 650);
    stopDrive();
    setClawfor(-127, 3000);
    setClaw(-50);
    vexSleep(250);
    setArmfor(70, 3000);
    resetEnc();
    driveFBfor(-110, -600);
    setDriveFB(-45);
    setArmfor(65, 2150);
    setArm(0);
    stopDrive();
    vexSleep(250);
    setClawfor(127, 1900);
    setClaw(0);
    resetEnc();
    setClawfor(-50, 1600);
    setArmfor(-70, 3900);
    setArm(15);
}

void autoBack(void)
{
    resetEnc();
    setClawfor(-60, 1200);
    setClaw(0);
    vexSleep(250);
    driveFBfor(-60, -600);
    stopDrive();
    vexSleep(500);
    resetEnc();
    setClawfor(-90, 1500);
    setClaw(0);
    vexSleep(250);
    driveFBfor(40, 250);
    stopDrive();
    setClawfor(-127, 3000);
    setClaw(-40);
    setArmfor(100, 3300);
    setArm(10);
    driveFBfor(-90, -450);
    setDriveFB(-45);
    setArmfor(127, 2150);
    setArm(0);
    stopDrive();
    setClawfor(127, 1900);
    setClaw(0);
    resetEnc();
}

void autoClawOut(void)
{
    resetEnc();
    driveFBfor(60, 300);
    stopDrive();
    vexSleep(500);
    startAuto();
}