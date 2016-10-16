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
    setLift(0);
    driveFB(120);
    vexSleep(700);
    driveFB(0);
    vexSleep(100);
    driveFB(-110);
    vexSleep(400);
    driveFB(0);
    vexSleep(500);
}

void autoLeft(void) {
    //phase 1
    turnLeft(60);
    vexSleep(400);
    driveFB(0);
    setLift(75);
    vexSleep(800);
    setLift(0);
    vexSleep(250);
    setLift(15);
    vexSleep(250);
    driveFB(60);
    vexSleep(1000);
    driveFB(30);
    vexSleep(500);
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
    turnRight(35);
    vexSleep(800);
    turnLeft(5);
    vexSleep(300);
    driveFB(0);
    vexSleep(500);
    driveFB(60);
    vexSleep(1300);
    driveFB(0);
    setLift(0);
    vexSleep(500);
    //Phase 4
    driveFB(-60);
    vexSleep(1200);
    driveFB(0);
    turnLeft(40);
    vexSleep(300);
    turnLeft(0);
    vexSleep(300);
    setLift(-100);
    driveFB(-50);
    vexSleep(300);
    setLift(0);
    vexSleep(200);
    driveFB(0);
}

void autoRight(void)
{
    //phase 1
    turnRight(60);
    vexSleep(400);
    driveFB(0);
    setLift(75);
    vexSleep(800);
    setLift(0);
    vexSleep(250);
    setLift(15);
    vexSleep(250);
    driveFB(60);
    vexSleep(1000);
    driveFB(30);
    vexSleep(500);
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
    turnLeft(45);
    vexSleep(800);
    turnRight(5);
    vexSleep(300);
    driveFB(0);
    vexSleep(500);
    driveFB(60);
    vexSleep(700);
    driveFB(0);
    setLift(0);
    vexSleep(500);
    //Phase 4
    driveFB(-60);
    vexSleep(700);
    driveFB(0);
    turnRight(50);
    vexSleep(300);
    turnRight(0);
    vexSleep(300);
    setLift(-100);
    driveFB(-50);
    vexSleep(300);
    setLift(0);
    vexSleep(200);
    driveFB(0);
}

void forkOut(void)
{
    setLift(60);
    vexSleep(300);
    setLift(0);
    vexSleep(200);
    setLift(-60);
    vexSleep(200);
    setLift(0);
    driveFB(-50);
    vexSleep(800);
    driveFB(0);
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
            switch(auton) {
                case 1:
                    autoLeft();
                    break;
                case 2:
                    autoRight();
                    break;
                case 3:
                    forkOut();
                    vexSleep(5000);
                    break;
            }
            vexSleep(10000);
            // Don't hog cpu
            vexSleep( 25 );
        }

    return (msg_t)0;
}