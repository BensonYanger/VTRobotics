#ifndef _PID_H_
#define _PID_H_

#include "vexstdinc.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LiftPidStruct {
    //pid constants
    int kp;
    int ki;
    int kd;

    //errors (error, integral, differential)
    int err;
    int interr;
    int differr;

    //time between calls
    int dt;
} lp;

#ifdef __cplusplus
}
#endif

#endif  /* _PID_H_ */