#include "vexstdinc.h"

#include "lift.h"

int16_t liftPosition;
int16_t liftTarget = 900;

//0 for task, 1 for manual
int16_t liftFlag = 0;

static WORKING_AREA(waLiftTask, 512);
msg_t
liftTask(void *arg)
{
    (void)arg;

    // must call
    vexTaskRegister("liftTask");

    // task
    while(!chThdShouldTerminate())
    {
        liftPosition = vexAdcGet(1);

        if(liftFlag == 0)
        {
            if (liftPosition + 90 < liftTarget) {
                vexMotorSet(kVexMotor_3, 127);
                vexMotorSet(kVexMotor_8, 127);
            } else if (liftPosition - 90 > liftTarget) {
                vexMotorSet(kVexMotor_3, -127);
                vexMotorSet(kVexMotor_8, -127);
            } else {
                vexMotorSet(kVexMotor_3, 0);
                vexMotorSet(kVexMotor_8, 0);
            }
        }
        
        if(liftFlag == 1)
        {
            if(vexControllerGet(Btn8U)) {
                vexMotorSet(kVexMotor_3, 127);
                vexMotorSet(kVexMotor_8, 127);
            } else if (vexControllerGet(Btn8R)) {
                vexMotorSet(kVexMotor_3, 127);
                vexMotorSet(kVexMotor_8, 127);
            } else {
                vexMotorSet(kVexMotor_3, 0);
                vexMotorSet(kVexMotor_8, 0);
            }

            if(vexControllerGet(Btn8UXmtr2)) {
                vexMotorSet(kVexMotor_3, 127);
                vexMotorSet(kVexMotor_8, 127);
            } else if (vexControllerGet(Btn8RXmtr2)) {
                vexMotorSet(kVexMotor_3, 127);
                vexMotorSet(kVexMotor_8, 127);
            } else {
                vexMotorSet(kVexMotor_3, 0);
                vexMotorSet(kVexMotor_8, 0);
            }
        }

        vexSleep(25);
    }
    
    return (msg_t)0;
}

int
startLiftTask(void) {
    // start lift task
    chThdCreateStatic(waLiftTask, sizeof(waLiftTask), NORMALPRIO - 1, liftTask, NULL);
    return 0;
}