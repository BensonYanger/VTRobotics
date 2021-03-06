#include "vexstdinc.h"

#include "init.h"

#include "drive.h"
#include "lcd.h"
#include "audio.h"
#include "lift.h"

/*-----------------------------------------------------------------------------*/
/** @brief      User initialize                                                */
/*-----------------------------------------------------------------------------*/
/** @details
 *  This function is called after all setup is complete and communication has
 *  been established with the master processor.
 *  Start other tasks and initialize user variables here
 */

void
vexUserInit()
{
    startLcdAuto();
	//startLiftTask();
}