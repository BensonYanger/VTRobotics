#ifndef _AUTOS_H_
#define _AUTOS_H_

#ifdef __cplusplus
extern "C" {
#endif

void driveFB(int16_t drive);
void driveLR(int16_t drive);
void turnLR(int16_t drive);
void setArm(int16_t lift);
void setClaw(int16_t claw);

void startAuto(void);
void autoLeft(void);
void autoRight(void);
void autoLeftNoCube(void);
void autoRightNoCube(void);

#ifdef __cplusplus
}
#endif

#endif  /* _AUTOS_H_ */