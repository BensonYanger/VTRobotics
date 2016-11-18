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

        // Don't hog cpu
        vexSleep(25);
    }

    return (msg_t)0;
}

static WORKING_AREA(waxDrive, 512);
msg_t
xDrive(void *arg) 
{
    int16_t joyLx = 0;
    int16_t joyLy = 0;
    int16_t joyRy = 0;
    int16_t joyRx = 0;

    (void)arg;

    // Register the task
    vexTaskRegister("xdrive");

    while(!chThdShouldTerminate()) 
    {
        joyLx = vexControllerGet(Ch4);
        joyLy = vexControllerGet(Ch3);
        joyRy = vexControllerGet(Ch2);
        joyRx = vexControllerGet(Ch1);

        if(abs(joyLy) > 15) {
            vexMotorSet(kVexMotor_4, joyLy);
            vexMotorSet(kVexMotor_6, joyLy);

            vexMotorSet(kVexMotor_5, joyLy);
            vexMotorSet(kVexMotor_7, joyLy);
        } else if(abs(joyLx) > 15) {
            vexMotorSet(kVexMotor_4, joyLx);
            vexMotorSet(kVexMotor_6, joyLx);
            
            vexMotorSet(kVexMotor_5, -joyLx);
            vexMotorSet(kVexMotor_7, -joyLx);
        } else if(abs(joyRx) > 15) {
            vexMotorSet(kVexMotor_4, joyRx);
            vexMotorSet(kVexMotor_6, -joyRx);
            
            vexMotorSet(kVexMotor_5, -joyRx);
            vexMotorSet(kVexMotor_7, joyRx);
        } else {
            vexMotorSet(kVexMotor_4, 0);
            vexMotorSet(kVexMotor_6, 0);
            
            vexMotorSet(kVexMotor_5, 0);
            vexMotorSet(kVexMotor_7, 0);
        }

        // Don't hog cpu
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

int
startxDrive(void) {
    // start tank drive
    chThdCreateStatic(waxDrive, sizeof(waxDrive), NORMALPRIO - 1, xDrive, NULL);
    return 0;
}