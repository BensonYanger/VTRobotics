#ifndef _AUTOF_H_
#define _AUTOF_H_

#ifdef __cplusplus
extern "C" {
#endif

void stopDrive(void);

void setDriveFB(int16_t drive);
void driveFBfor(int16_t drive, int16_t quad);

void setDriveLR(int16_t drive);
void driveLRfor(int16_t drive, int16_t quad);

void setTurnLR(int16_t drive);
void turnLRfor(int16_t drive, int16_t quad);

void setArm(int16_t lift);
void setArmfor(int16_t lift, int16_t pot);
void stopArm(void);

void setClaw(int16_t lift);
void setClawfor(int16_t claw, int16_t pot);
void stopClaw(void);

#ifdef __cplusplus
}
#endif

#endif  /* _AUTOF_H_ */