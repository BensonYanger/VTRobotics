#include "vexstdinc.h"

#include "lcd.h"

static WORKING_AREA(waVexLcdAuto, 512);

msg_t
lcdAuto(void *arg) {

    (void)arg;

    // register the task
    vexTaskRegister("lcdauto");

    // call lcdmenu struct
    lcdMenu lcdmenu;
    lcdmenu.page = 1;
    lcdmenu.pageMin = 1;
    lcdmenu.pageMax = 5;

    while(true) {
        if((vexControllerCompetitonState() & kFlagDisabled) == kFlagDisabled) {
            if(vexLcdButtonGet(VEX_LCD_DISPLAY_1) == 1) {
                if(lcdmenu.page == lcdmenu.pageMin) {
                    lcdmenu.page = lcdmenu.pageMax;
                    vexSleep(100);
                } else {
                    lcdmenu.page--;
                    vexSleep(100);
                }
            }
            if(vexLcdButtonGet(VEX_LCD_DISPLAY_1) == 4) {
                if(lcdmenu.page == lcdmenu.pageMax) {
                    lcdmenu.page = lcdmenu.pageMin;
                    vexSleep(100);
                } else {
                    lcdmenu.page++;
                    vexSleep(100);
                }
            }

            if(lcdmenu.page == 1 && auton != 1) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "       1        ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "    i dunno     ");
                if(vexLcdButtonGet(VEX_LCD_DISPLAY_1) == 2) {
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, " Autonomous Has ");
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, " Been Selected! ");
                    vexSleep(1000);
                }
            } else if(lcdmenu.page == 1 && auton == 1) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "      [1]       ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "    i dunno     ");
            } else if(lcdmenu.page == 2 && auton != 2) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "       2        ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "      idk       ");
                if(vexLcdButtonGet(VEX_LCD_DISPLAY_1) == 2) {
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, " Autonomous Has ");
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, " Been Selected! ");
                    vexSleep(1000);
                }
            } else if(lcdmenu.page == 2 && auton == 2) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "      [2]       ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "      idk       ");
            }
        }
        

        // give CPU time
        vexSleep(25);
    }

    return (msg_t)0;

}