#include "vexstdinc.h"

#include "auto.h"
#include "autos.h"
#include "autof.h"
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
                    autoLeftCorner();
                    break;
                case 2:
                    autoRightCorner();
                    break;
                case 3:
                    autoLeftCube();
                    break;
                case 4:
                    autoRightCube();
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