#ifndef SIMON_ILED_H
#define	SIMON_ILED_H
#include <xc.h> // include processor files - each processor file is guarded.  


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    void write0(void);
    void write1(void);
    void writeColor(int r, int g, int b);
    void displayColor(char keypadChar);
    void initLED(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* neuman346_lab3_CLib_v001_H */

