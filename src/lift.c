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

            if (liftPosition + 70 < liftTarget) {
                vexMotorSet(kVexMotor_3, 127);
                vexMotorSet(kVexMotor_8, 127);
            } else if (liftPosition - 70 > liftTarget) {
                vexMotorSet(kVexMotor_3, -127);
                vexMotorSet(kVexMotor_8, -127);
            } else {
                vexMotorSet(kVexMotor_3, 0);
                vexMotorSet(kVexMotor_8, 0);
            }

        if(vexControllerGet(Btn8U)) {
            liftTarget = 2800;
        } else if (vexControllerGet(Btn8R)) {
            liftTarget = 800;
        }
        if (vexControllerGet(Ch3Xmtr2)) {
            liftTarget = liftTarget + vexControllerGet(Ch3Xmtr2)/6;
        }

        if(liftTarget < 600) {
            liftTarget = 600;
        } else if (liftTarget > 2900) {
            liftTarget = 2900;
        }

        vexSleep(50);
    }
    
    return (msg_t)0;
}

int
startLiftTask(void) {
    // start lift task
    chThdCreateStatic(waLiftTask, sizeof(waLiftTask), NORMALPRIO - 1, liftTask, NULL);
    return 0;
}