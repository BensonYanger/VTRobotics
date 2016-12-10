#include "vexstdinc.h"

#include "auto.h"
#include "lcd.h"

#include "drive.h"
#include "lift.h"

void driveFB(int drive)
{
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_6, drive);
    vexMotorSet(kVexMotor_5, drive);
    vexMotorSet(kVexMotor_7, drive);
}

void driveLR(int drive)
{
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_6, drive);
    vexMotorSet(kVexMotor_5, -drive);
    vexMotorSet(kVexMotor_7, -drive);
}

void turnLR(int drive)
{
    vexMotorSet(kVexMotor_4, drive);
    vexMotorSet(kVexMotor_6, -drive);

    vexMotorSet(kVexMotor_5, -drive);
    vexMotorSet(kVexMotor_7, drive);
}

void setArm(int lift)
{
    vexMotorSet(kVexMotor_2, lift);
    vexMotorSet(kVexMotor_9, lift);
}

void setClaw(int claw)
{
    vexMotorSet(kVexMotor_1, claw);
    vexMotorSet(kVexMotor_10, claw);
}

void startAuto(void)
{
    liftTarget = 2350;
    driveFB(-120);
    vexSleep(1000);
    driveFB(0);
    vexSleep(100);
    driveFB(127);
    vexSleep(500);
    driveFB(-127);
    vexSleep(750);
    driveFB(0);
    vexSleep(250);
}

void autoLeft(void)
{
    //STAGE 1: KNOCK OFF STARS FROM FENCE
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
    while(vexEncoderGet(kVexQuadEncoder_1) > -180)
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
    while(vexEncoderGet(kVexQuadEncoder_1) > -180)
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
    while(vexEncoderGet(kVexQuadEncoder_1) > -200)
    {
        driveFB(-50);
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
        driveFB(50);
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
    while(vexEncoderGet(kVexQuadEncoder_1) > -300)
    {
        driveFB(-60);
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
    while(vexEncoderGet(kVexQuadEncoder_1) > -180)
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
    while(vexEncoderGet(kVexQuadEncoder_1) > -180)
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
        driveFB(-50);
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
        driveFB(50);
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
        driveFB(-60);
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
    while(vexEncoderGet(kVexQuadEncoder_1) > -180)
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
    while(vexEncoderGet(kVexQuadEncoder_1) > -180)
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
    while(vexEncoderGet(kVexQuadEncoder_1) > -180)
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
    while(vexEncoderGet(kVexQuadEncoder_1) > -180)
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

    startLiftTask();

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
                    autoLeftNoCube();
                    break;
                case 4:
                    autoRightNoCube();
                    break;
                case 5:
                    break;
                default:
                    break;
            }
            vexSleep(10000);
            // Don't hog cpu
            vexSleep( 25 );
        }

    return (msg_t)0;
}