#ifndef _AUTO_H_
#define _AUTO_H_

#ifdef __cplusplus
extern "C" {
#endif

void driveFB(int16_t drive);
void driveLR(int16_t drive);
void turnLR(int16_t drive);
void setArm(int16_t lift);
void setClaw(int16_t claw);

#ifdef __cplusplus
}
#endif

#endif  /* _AUTO_H_ */