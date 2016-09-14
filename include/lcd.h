#ifndef _LCD_H_
#define _LCD_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct lcdMenu {
    int pageMin;
    int pageMax;
    int page;
    int auton;
}lcdMenu;

msg_t lcdAuto(void *arg);

#ifdef __cplusplus
}
#endif

#endif  /* _LCD_H_ */