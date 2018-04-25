#ifndef SIMON_KEYPAD_H
#define	SIMON_KEYPAD_H
#include <xc.h> // include processor files - each processor file is guarded.  


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    void delay(int time);
    void initKeyPad(void);
    char readKeyPadRAW(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* neuman346_lab3_CLib_v001_H */

