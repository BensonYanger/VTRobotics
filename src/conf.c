#include "vexstdinc.h"

#include "conf.h"

// Digi IO configuration
static  vexDigiCfg  dConfig[kVexDigital_Num] = {
        { kVexDigital_1,    kVexSensorDigitalOutput,  kVexConfigOutput,     0 },
        { kVexDigital_2,    kVexSensorDigitalOutput,  kVexConfigOutput,     0 },
        { kVexDigital_3,    kVexSensorDigitalOutput,  kVexConfigOutput,     0 },
        { kVexDigital_4,    kVexSensorDigitalInput,   kVexConfigInput,      0 },
        { kVexDigital_5,    kVexSensorDigitalInput,   kVexConfigInput,      0 },
        { kVexDigital_6,    kVexSensorQuadEncoder,    kVexConfigQuadEnc1,   kVexQuadEncoder_1 },
        { kVexDigital_7,    kVexSensorQuadEncoder,    kVexConfigQuadEnc2,   kVexQuadEncoder_1 },
        { kVexDigital_8,    kVexSensorQuadEncoder,    kVexConfigQuadEnc1,   kVexQuadEncoder_2 },
        { kVexDigital_9,    kVexSensorQuadEncoder,    kVexConfigQuadEnc2,   kVexQuadEncoder_2 },
        { kVexDigital_10,   kVexSensorDigitalOutput,  kVexConfigOutput,     0 },
        { kVexDigital_11,   kVexSensorQuadEncoder,    kVexConfigQuadEnc1,   kVexQuadEncoder_3 },
        { kVexDigital_12,   kVexSensorQuadEncoder,    kVexConfigQuadEnc2,   kVexQuadEncoder_3 }
};

static  vexMotorCfg mConfig[kVexMotorNum] = {
        { kVexMotor_1,      kVexMotor393T,           kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_2,      kVexMotor393T,           kVexMotorNormal,       kVexSensorQuadEncoder,        kVexQuadEncoder_3 },
        { kVexMotor_3,      kVexMotor393T,           kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_4,      kVexMotor393S,           kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_5,      kVexMotor393S,           kVexMotorReversed,     kVexSensorQuadEncoder,        kVexQuadEncoder_1 },
        { kVexMotor_6,      kVexMotor393S,           kVexMotorReversed,     kVexSensorNone,        0 },
        { kVexMotor_7,      kVexMotor393S,           kVexMotorNormal,       kVexSensorQuadEncoder,        kVexQuadEncoder_2 },
        { kVexMotor_8,      kVexMotor393T,           kVexMotorReversed,     kVexSensorNone,        0 },
        { kVexMotor_9,      kVexMotor393T,           kVexMotorReversed,     kVexSensorQuadEncoder,        kVexQuadEncoder_3 },
        { kVexMotor_10,     kVexMotor393T,           kVexMotorReversed,     kVexSensorNone,        0 }
};


/*-----------------------------------------------------------------------------*/
/** @brief      User setup                                                     */
/*-----------------------------------------------------------------------------*/
/** @details
 *  The digital and motor ports can (should) be configured here.
 */
void
vexUserSetup()
{
	vexDigitalConfigure( dConfig, DIG_CONFIG_SIZE( dConfig ) );
	vexMotorConfigure( mConfig, MOT_CONFIG_SIZE( mConfig ) );
}
