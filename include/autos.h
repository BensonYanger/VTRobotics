#ifndef _AUTOS_H_
#define _AUTOS_H_

#ifdef __cplusplus
extern "C" {
#endif

void stopDrive(void);
void driveFB(int16_t drive, int16_t pot);
void driveLR(int16_t drive, int16_t pot);
void turnLR(int16_t drive, int16_t pot);
void setArm(int16_t lift, int16_t pot);
void stopArm(void);
void setClaw(int16_t claw, int16_t pot);
void stopClaw(void);

void startAuto(void);
void autoLeftCorner(void);
void autoRightCorner(void);
void autoLeftCube(void);
void autoRightCube(void);

#ifdef __cplusplus
}
#endif

#endif  /* _AUTOS_H_ */