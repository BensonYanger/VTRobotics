#ifndef _LCD_H_
#define _LCD_H_

#ifdef __cplusplus
extern "C" {
#endif

extern int auton;

typedef struct lcdMenu {
    int pageMin;
    int pageMax;
    int page;
}lcdMenu;

msg_t lcdAuto(void *arg);
int startLcdAuto(void);

#ifdef __cplusplus
}
#endif

#endif  /* _LCD_H_ */