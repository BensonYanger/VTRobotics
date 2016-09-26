#include "vexstdinc.h"

#include "drive.h"

static WORKING_AREA(waTankDrive, 512);
msg_t
tankDrive(void *arg) 
{
    int16_t joyLy = 0;
    int16_t joyRy = 0;

    (void)arg;

    // Register the task
    vexTaskRegister("tank drive");

    while(1) 
    {
        joyLy = vexControllerGet(Ch3);
        joyRy = vexControllerGet(Ch2);

        vexMotorSet(kVexMotor_4, joyLy);
        vexMotorSet(kVexMotor_5, joyLy);

        vexMotorSet(kVexMotor_6, joyRy);
        vexMotorSet(kVexMotor_7, joyRy);

        // Don't rest cpu
        vexSleep(25);
    }

    return (msg_t)0;
}

int
startTankDrive() {
    // start tank drive
    chThdCreateStatic(waTankDrive, sizeof(waTankDrive), NORMALPRIO - 1, tankDrive, NULL);
    if (!vexTaskIsRegistered("tank drive")) {
        return -1;
    }
    return 0;
}