#ifndef _DRIVE_H_
#define _DRIVE_H_

#ifdef __cplusplus
extern "C" {
#endif

msg_t tankDrive(void *arg);
int startTankDrive();

#ifdef __cplusplus
}
#endif

#endif  /* _DRIVE_H_ */