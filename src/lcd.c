#include "vexstdinc.h"

#include "lcd.h"

static WORKING_AREA(waLcdAuto, 512);

int auton = 0;

msg_t
lcdAuto(void *arg) {

    (void)arg;

    // register the task
    //vexTaskRegister("lcdauto");

    // call lcdmenu struct
    lcdMenu lcdmenu;
    lcdmenu.page = 1;
    lcdmenu.pageMin = 1;
    lcdmenu.pageMax = 4;

    //testing
    while(true) {
        if((vexControllerCompetitonState() & kFlagDisabled) == kFlagDisabled)
        {
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
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "   left corner  ");
                if(vexLcdButtonGet(VEX_LCD_DISPLAY_1) == 2) {
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, " Autonomous Has ");
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, " Been Selected! ");
                    auton = 1;
                    vexSleep(500);
                }
            } else if(lcdmenu.page == 1 && auton == 1) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "      [1]       ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "   left corner  ");
            } else if(lcdmenu.page == 2 && auton != 2) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "       2        ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "  right corner  ");
                if(vexLcdButtonGet(VEX_LCD_DISPLAY_1) == 2) {
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, " Autonomous Has ");
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, " Been Selected! ");
                    auton = 2;
                    vexSleep(500);
                }
            } else if(lcdmenu.page == 2 && auton == 2) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "      [2]       ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "  right corner  ");
            } else if(lcdmenu.page == 3 && auton != 3) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "       3        ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "     back up    ");
                 if(vexLcdButtonGet(VEX_LCD_DISPLAY_1) == 2) {
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, " Autonomous Has ");
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, " Been Selected! ");
                    auton = 3;
                    vexSleep(500);
                }
            } else if(lcdmenu.page == 3 && auton == 3) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "      [3]       ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "     back up    ");
            } else if(lcdmenu.page == 4 && auton != 4) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "       4        ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "    claw out    ");
                 if(vexLcdButtonGet(VEX_LCD_DISPLAY_1) == 2) {
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, " Autonomous Has ");
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, " Been Selected! ");
                    auton = 4;
                    vexSleep(500);
                }
            } else if(lcdmenu.page == 4 && auton == 4) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "      [4]       ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "    claw out    ");
            } else if(lcdmenu.page == 5 && auton != 5) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "       5        ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "    claw out    ");
                 if(vexLcdButtonGet(VEX_LCD_DISPLAY_1) == 2) {
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, " Autonomous Has ");
                    vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, " Been Selected! ");
                    auton = 5;
                    vexSleep(500);
                }
            } else if(lcdmenu.page == 5 && auton == 5) {
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_1, "      [5]       ");
                vexLcdPrintf(VEX_LCD_DISPLAY_1, VEX_LCD_LINE_2, "    claw out    ");
            }
        }
        

        // give CPU time
        vexSleep(100);
    }

    return (msg_t)0;

}

int
startLcdAuto(void) {
    // start tank drive
    chThdCreateStatic(waLcdAuto, sizeof(waLcdAuto), NORMALPRIO - 1, lcdAuto, NULL);
    return 0;
}