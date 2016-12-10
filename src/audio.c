#include "vexstdinc.h"

#include "audio.h"

char *Flinstones = "Flinstones:d=4,o=5,b=40:32p,16f6,16a#,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,d6,16f6,16a#.,16a#6,32g6,16f6,16a#.,32f6,32f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,a#,16a6,16d.6,16a#6,32a6,32a6,32g6,32f#6,32a6,8g6,16g6,16c.6,32a6,32a6,32g6,32g6,32f6,32e6,32g6,8f6,16f6,16a#.,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#6,16c7,8a#.6";
char *Mario = "Super Mario:d=4,o=5,b=100:16e6,16e6,32p,8e6,16c6,8e6,8g6,8p,8g,8p,"
                "8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,16p,"
                "8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,16p,"
                "8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,"
                "8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16c7,16p,16c7,16c7,8p.,"
                "8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,""8p,16d#6,8p,16d6,8p,16c6";
char *Zelda = "Zelda1:d=4,o=5,b=125:a#,f.,8a#,16a#,16c6,16d6,16d#6,2f6,8p,8f6,16f.6,16f#6,16g#.6,2a#.6,16a#.6,16g#6,16f#.6,8g#.6,16f#.6,2f6,f6,8d#6,16d#6,16f6,2f#6,8f6,8d#6,8c#6,16c#6,16d#6,2f6,8d#6,8c#6,8c6,16c6,16d6,2e6,g6,8f6,16f,16f,8f,16f,16f,8f,16f,16f,8f,8f,a#,f.,8a#,16a#,16c6,16d6,16d#6,2f6,8p,8f6,16f.6,16f#6,16g#.6,2a#.6,c#7,c7,2a6,f6,2f#.6,a#6,a6,2f6,f6,2f#.6,a#6,a6,2f6,d6,2d#.6,f#6,f6,2c#6,a#,c6,16d6,2e6,g6,8f6,16f,16f,8f,16f,16f,8f,16f,16f,8f,8f";
char *StarWars = "StarWars:d=4,o=5,b=45:32p,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#.6,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#6";
static WORKING_AREA(waSpeakerPress, 512);
msg_t
speakerPress(void *arg)
{
    (void)arg;

    //register task
    vexTaskRegister("speakerpress");

    while(!chThdShouldTerminate())
    {
        if(vexControllerGet(Btn7U)) {
            vexAudioPlayRtttl(Flinstones, 128, 0);
        }
        if(vexControllerGet(Btn7R)) {
            vexAudioPlayRtttl(Mario, 128, 0);
        }
        if(vexControllerGet(Btn7L)) {
            vexAudioPlayRtttl(Zelda, 128, 0);
        }
        if(vexControllerGet(Btn7D)) {
            vexAudioPlayRtttl(StarWars, 128, 0);
        }

        if(vexControllerGet(Btn7UXmtr2)) {
            vexAudioPlayRtttl(Flinstones, 128, 0);
        }
        if(vexControllerGet(Btn7RXmtr2)) {
            vexAudioPlayRtttl(Mario, 128, 0);
        }
        if(vexControllerGet(Btn7LXmtr2)) {
            vexAudioPlayRtttl(Zelda, 128, 0);
        }
        if(vexControllerGet(Btn7DXmtr2)) {
            vexAudioPlayRtttl(StarWars, 128, 0);
        }
        
        vexSleep(25);
    }
    return (msg_t)0;
}

int
startSpeakerPress(void) {
    // start speaker
    chThdCreateStatic(waSpeakerPress, sizeof(waSpeakerPress), NORMALPRIO - 1, speakerPress, NULL);
    return 0;
}