.include "xc.inc"
.text
.global _wait_write0_preclear, _wait_write1_preclear, _wait_write0_postclear, _wait_write1_postclear, _dummy_code

;delays to create write0 and write1 in c    
_wait_write0_preclear:
    repeat #2 
    nop
    return    
    
_wait_write1_preclear:
    repeat #7 
    nop
    return    
    
_wait_write0_postclear:
    repeat #6 
    nop
    return    
    
_wait_write1_postclear:
    repeat #0 
    nop
    return  

_dummy_code:
    repeat #0 
    nop
    return      
    