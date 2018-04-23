/* 
 * File:   neuma346_lab3_CLib_keypad.h
 * Author: Emily
 *
 * Created on February 21, 2018, 4:27 PM
 */

#ifndef NEUMA346_LAB3_CLIB_KEYPAD_H
#define	NEUMA346_LAB3_CLIB_KEYPAD_H
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

