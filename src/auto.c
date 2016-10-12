#include "vexstdinc.h"

#include "auto.h"

void driveFB(int drive)
{
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_7, drive);
    vexMotorSet(kVexMotor_5, drive);
    vexMotorSet(kVexMotor_6, drive);
}

void setLift(int lift)
{
    vexMotorSet(kVexMotor_2, lift);
    vexMotorSet(kVexMotor_3, lift);
    vexMotorSet(kVexMotor_8, lift);
    vexMotorSet(kVexMotor_9, lift);
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
            driveFB(127);
            vexSleep(750);
            driveFB(0);
            vexSleep(150);
            driveFB(-127);
            vexSleep(500);
            driveFB(0);
            setLift(127);
            vexSleep(500);
            setLift(0);
            vexSleep(150);
            setLift(-127);
            vexSleep(350);
            setLift(0);
            vexSleep(12500);
            // Don't hog cpu
            vexSleep( 25 );
        }

    return (msg_t)0;
}