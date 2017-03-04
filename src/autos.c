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
    setArmfor(127, 3000);
    stopArm();
    setArmfor(-64, 3750);
    setArm(10);
    setClawfor(-60, 3000);
    stopClaw();
    vexSleep(250);
    setClawfor(60, 1000);
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