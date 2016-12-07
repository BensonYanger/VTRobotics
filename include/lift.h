#ifndef _LIFT_H_
#define _LIFT_H_

#ifdef __cplusplus
extern "C" {
#endif

extern int16_t liftPosition;
extern int16_t liftTarget;

msg_t liftTask(void *arg);
int startLiftTask(void);

#ifdef __cplusplus
}
#endif

#endif  /* _LIFT_H_ */