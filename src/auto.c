#include "vexstdinc.h"

#include "auto.h"
#include "lcd.h"

void driveFB(int drive)
{
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_7, drive);
    vexMotorSet(kVexMotor_5, drive);
    vexMotorSet(kVexMotor_6, drive);
}

void turnLeft(int drive)
{
    vexMotorSet(kVexMotor_4, -drive);
    vexMotorSet(kVexMotor_7, -drive);

    vexMotorSet(kVexMotor_5, drive);
    vexMotorSet(kVexMotor_6, drive);
}

void turnRight(int drive)
{
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_7, drive);

    vexMotorSet(kVexMotor_5, -drive);
    vexMotorSet(kVexMotor_6, -drive);
}

void setLift(int lift)
{
    vexMotorSet(kVexMotor_2, lift);
    vexMotorSet(kVexMotor_3, lift);
    vexMotorSet(kVexMotor_8, lift);
    vexMotorSet(kVexMotor_9, lift);
}

void startAuto(void)
{
    driveFB(127);
    vexSleep(1000);
    driveFB(0);
    setLift(0);
    vexSleep(100);
    driveFB(-100);
    vexSleep(800);
    driveFB(0);
    setLift(0);
    vexSleep(500);
}

void autoLeft(void) {
    //phase 1
    turnLeft(25);
    vexSleep(400);
    driveFB(0);
    vexSleep(300);
    driveFB(75);
    vexSleep(400);
    setLift(110);
    vexSleep(400);
    driveFB(0);
    vexSleep(200);
    setLift(0);
    driveFB(80);
    vexSleep(300);
    driveFB(0);
    vexSleep(300);
    //phase 2
    driveFB(-100);
    vexSleep(600);
    driveFB(5);
    vexSleep(250);
    driveFB(0);
    vexSleep(300);
    //phase 3
    turnRight(40);
    vexSleep(800);
    turnLeft(5);
    vexSleep(300);
    driveFB(0);
    vexSleep(500);
    driveFB(60);
    vexSleep(700);
    driveFB(0);
    setLift(0);
    vexSleep(300);
}

void autoRight(void)
{
    //phase 1
    turnRight(25);
    vexSleep(400);
    driveFB(0);
    vexSleep(300);
    driveFB(75);
    vexSleep(400);
    setLift(110);
    vexSleep(400);
    driveFB(0);
    vexSleep(200);
    setLift(0);
    driveFB(80);
    vexSleep(300);
    driveFB(0);
    vexSleep(300);
    //phase 2
    driveFB(-100);
    vexSleep(600);
    driveFB(5);
    vexSleep(250);
    driveFB(0);
    vexSleep(300);
    //phase 3
    turnLeft(40);
    vexSleep(800);
    turnRight(5);
    vexSleep(300);
    driveFB(0);
    vexSleep(500);
    driveFB(60);
    vexSleep(700);
    driveFB(0);
    setLift(0);
    vexSleep(300);
}

void autoStraight(void) {
    //Phase 1
    turnRight(25);
    vexSleep(450);
    driveFB(0);
    vexSleep(100);
    driveFB(75);
    vexSleep(400);
    setLift(110);
    vexSleep(400);
    driveFB(0);
    vexSleep(200);
    setLift(0);
    //Phase 2
    driveFB(-90);
    vexSleep(500);
    driveFB(5);
    vexSleep(300);
    //Phase 3
    turnLeft(40);
    vexSleep(600);
    driveFB(0);
    vexSleep(300);
    driveFB(80);
    vexSleep(500);
    driveFB(0);
    vexSleep(300);
    driveFB(-80);
    vexSleep(400);
    setLift(-100);
    vexSleep(300);
    driveFB(0);
    setLift(0);
    vexSleep(300);
}

/*-----------------------------------------------------------------------------*/
/** @brief      Autonomous                                                     */
/*-----------------------------------------------------------------------------*/
/** @details
 *  This thread is started when the autonomous period is started
 */
msg_t
vexAutonomous( void *arg )
{
    (void)arg;

    // Must call this
    vexTaskRegister("auton");

    while(1)
        {
            startAuto();
            if(auton == 1) {
                autoStraight();
            }
            else if(auton == 2) {
                autoLeft();
            }
            else if(auton == 3) {
                autoRight();
            }
            else if(auton == 4) {
                vexSleep(5000);
            }
            vexSleep(10000);
            // Don't hog cpu
            vexSleep( 25 );
        }

    return (msg_t)0;
}