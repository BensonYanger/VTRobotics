#include "vexstdinc.h"

#include "auto.h"
#include "autos.h"
#include "lcd.h"

#include "drive.h"


/*-----------------------------------------------------------------------------*/
/** @brief      Autonomous                                                     */
/*-----------------------------------------------------------------------------*/
/** @details
 *  This thread is started when the autonomous period is started
 */
msg_t
vexAutonomous( void *arg )
{
    (void)arg;

    // Must call this
    vexTaskRegister("auton");

    while(1)
        {
            startAuto();
            switch(auton) {
                case 1:
                    autoLeft();
                    break;
                case 2:
                    autoRight();
                    break;
                case 3:
                    autoLeftNoCube();
                    break;
                case 4:
                    autoRightNoCube();
                    break;
                case 5:
                    break;
                default:
                    break;
            }
            vexSleep(10000);
            // Don't hog cpu
            vexSleep( 25 );
        }

    return (msg_t)0;
}