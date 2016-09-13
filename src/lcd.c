#include "vexstdinc.h"

#include "lcd.h"

static WORKING_AREA(waVexLcdAuto, 512);

msg_t
lcdAuto(void *arg) {

    (void)arg;

    // Leave the following untouched
    int lcdScreenMin = 0;
    int lcdCurrScreen = 0;
    int lcdScreenMax = 5;

    while(true) {
        if((vexControllerCompetitonState() & kFlagDisabled) == kFlagDisabled) {
            
        }
        

        // give CPU time
        vexSleep(25);
    }

    return (msg_t)0;

}