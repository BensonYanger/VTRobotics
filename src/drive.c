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
    vexTaskRegister("tankdrive");

    while(!chThdShouldTerminate()) 
    {
        joyLy = vexControllerGet(Ch3);
        joyRy = vexControllerGet(Ch2);

        vexMotorSet(kVexMotor_4, joyLy);
        vexMotorSet(kVexMotor_7, joyLy);

        vexMotorSet(kVexMotor_5, joyRy);
        vexMotorSet(kVexMotor_6, joyRy);

        // Don't rest cpu
        vexSleep(25);
    }

    return (msg_t)0;
}

int
startTankDrive(void) {
    // start tank drive
    chThdCreateStatic(waTankDrive, sizeof(waTankDrive), NORMALPRIO - 1, tankDrive, NULL);
    return 0;
}