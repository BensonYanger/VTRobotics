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
    vexSleep(300);
    setLift(127);
    vexSleep(500);
    driveFB(0);
    setLift(0);
    vexSleep(100);
    driveFB(-100);
    setLift(-100);
    vexSleep(400);
    driveFB(0);
    setLift(0);
}

void autoLeft(void)
{
    turnLeft(30);
    vexSleep(400);
    driveFB(0);
    vexSleep(100);
    driveFB(80);
    vexSleep(100);
    setLift(127);
    vexSleep(700);
    driveFB(0);
    vexSleep(200);
    setLift(0);
    driveFB(80);
    vexSleep(300);
    driveFB(0);
    vexSleep(100);
    driveFB(-100);
    vexSleep(600);
    driveFB(5);
    vexSleep(50);
    driveFB(0);
    vexSleep(250);
    turnRight(45);
    vexSleep(800);
    turnLeft(5);
    vexSleep(50);
    driveFB(0);
}

void autoRight(void)
{
    turnRight(30);
    vexSleep(400);
    driveFB(0);
    vexSleep(100);
    driveFB(80);
    vexSleep(100);
    setLift(127);
    vexSleep(700);
    driveFB(0);
    vexSleep(200);
    setLift(0);
    driveFB(80);
    vexSleep(300);
    driveFB(0);
    vexSleep(100);
    driveFB(-100);
    vexSleep(600);
    driveFB(5);
    vexSleep(50);
    driveFB(0);
    vexSleep(250);
    turnLeft(45);
    vexSleep(800);
    turnRight(5);
    vexSleep(50);
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
            if(auton == 1) {
                autoLeft();
            }
            else if(auton == 2) {
                autoRight();
            }
            vexSleep(12500);
            // Don't hog cpu
            vexSleep( 25 );
        }

    return (msg_t)0;
}