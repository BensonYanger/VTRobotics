#include "vexstdinc.h"

#include "pid.h"

int liftCounts;

int speedCalc(void) {
    liftCounts = vexEncoderGet(1);
    return liftCounts;
}

static WORKING_AREA(waLiftPid, 512);
msg_t
liftPid(void *arg)
{
    //call the pid struct
    lp lp;

    lp.kp = 1;
    lp.ki = 1;
    lp.kd = 1;

    lp.err = 0;
    lp.interr = 0;
    lp.differr = 0;

    lp.dt = 0;

    (void)arg;

    //register the task
    vexTaskRegister("liftpid");

    while(true) {
        speedCalc();
    }

    return (msg_t)0;
}