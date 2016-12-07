#include "vexstdinc.h"

#include "lift.h"

int16_t liftPosition;
int16_t liftTarget = 900;

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

        if(vexControllerGet(Btn8U)) {
            liftTarget = 3000;
        } else if (vexControllerGet(Btn8R)) {
            liftTarget = 2300;
        } else if (vexControllerGet(Btn8R)) {
            liftTarget = 900;
        }

        if(liftPosition + 50 < liftTarget) {
            vexMotorSet(kVexMotor_3, 127);
            vexMotorSet(kVexMotor_7, 127);
        } else if (liftPosition - 50 > liftTarget) {
            vexMotorSet(kVexMotor_3, -127);
            vexMotorSet(kVexMotor_7, -127);
        } else {
            vexMotorSet(kVexMotor_3, 0);
            vexMotorSet(kVexMotor_7, 0);
        }
    }
    return (msg_t)0;
}

int
startLiftTask(void) {
    // start lift task
    chThdCreateStatic(waLiftTask, sizeof(waLiftTask), NORMALPRIO - 1, liftTask, NULL);
    return 0;
}