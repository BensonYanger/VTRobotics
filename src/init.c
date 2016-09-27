#include "vexstdinc.h"

#include "init.h"

#include "drive.h"

/*-----------------------------------------------------------------------------*/
/** @brief      User initialize                                                */
/*-----------------------------------------------------------------------------*/
/** @details
 *  This function is called after all setup is complete and communication has
 *  been established with the master processor.
 *  Start other tasks and initialize user variables here
 */
<<<<<<< HEAD
void initialize() {
    setTeamName("600R");
}
=======
void
vexUserInit()
{
    startTankDrive();
}
>>>>>>> parent of f1fa44d... switch to pros cause convex is still not behaving
