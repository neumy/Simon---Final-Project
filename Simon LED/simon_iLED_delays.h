#ifndef SIMON_ILED_DELAYS_H
#define SIMON_ILED_DELAYS_H

#ifdef	__cplusplus
extern "C" {
#endif

void wait_write0_preclear(void);
void wait_write1_preclear(void);
void wait_write0_postclear(void);
void wait_write1_postclear(void);
void _dummy_code(void);

#ifdef	__cplusplus
}
#endif

#endif	
