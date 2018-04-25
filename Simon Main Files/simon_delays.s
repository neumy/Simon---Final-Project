.include "xc.inc"
.text                       
.global  _wait_50us, _wait_1ms, _wait_1us, _dummycode

;general delays    
_wait_50us:
    repeat #793 
    nop
    return 
    
_wait_1ms:
    repeat #15993 
    nop
    return
    
_wait_1us:
    repeat #9 
    nop
    return
    
_dummycode:
    repeat #0 
    nop
    return     
    