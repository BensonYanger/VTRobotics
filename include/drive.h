#ifndef _DRIVE_H_
#define _DRIVE_H_

#include "vexstdinc.h"

#ifdef __cplusplus
extern "C" {
#endif

msg_t tankDrive(void *arg);
int startTankDrive(void);
msg_t xDrive(void *arg);
int startxDrive(void);

#ifdef __cplusplus
}
#endif

#endif  /* _DRIVE_H_ */