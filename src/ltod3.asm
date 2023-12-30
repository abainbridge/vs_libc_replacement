.686P
.MODEL FLAT, C
.CODE
.xmm

; UNTESTED

; Convert 64-bit int to double. Input is in EDX and ECX. EDX has the high 32
; bits, ECX has the low.
;
; The compiler only seems to output calls to this when building for x86 in
; 32-bit mode and with SSE enabled.

_ltod3:
    mov         eax, ecx
    sar         eax, 31    ; Fill eax with sign bits.
    cmp         eax, edx   ; Is edx only full of sign bits too?
    jne         _ltod3_int64 ; If NE, then no it wasn't. We need to consider all 64 bits.
    cvtsi2sd    xmm0, ecx
    ret 0
end _ltod3


_ltod3_int64:
    ; If edx is positive we can treat the input as unsigned and get ultod3 to do the job for us.
    test        edx,edx
    jge         _ultod3

    movsd       xmm7,mmword ptr [_SignBit64 (1C68A0h)]
    neg         ecx
    adc         edx,0
    neg         edx
    call        _ultod3
    orps        xmm0,xmm7
    ret
end _ltod3_int64


_ultod3:
    test        edx,edx
    jne         _ultod3_int64
    cvtsi2sd    xmm0,ecx
    shr         ecx,1Fh
    movsd       xmm1,mmword ptr _Int32ToUInt32 (1C6880h)[ecx*8]
    addsd       xmm0,xmm1
    ret
end _ultod3


_ultod3_int64:
    movd        xmm4,dword ptr [_x0800 (1C68F8h)]
    movd        xmm5,dword ptr [_x17FF (1C68FCh)]
    movd        xmm6,dword ptr [_i1087 (1C68F4h)]
    movd        xmm0,ecx
    movd        xmm1,edx
    punpckldq   xmm0,xmm1
    mov         eax,20h
    bsr         ecx,edx
    sub         eax,ecx
    movd        xmm2,eax
    psllq       xmm0,xmm2
    movdqa      xmm3,xmm0
    psllq       xmm3,33h
    psrlq       xmm3,33h
    movdqa      xmm1,xmm3
    psrlq       xmm0,0Dh
    psllq       xmm0,1
    pcmpgtd     xmm3,xmm4
    punpckldq   xmm3,xmm3
    psubq       xmm0,xmm3
    pcmpgtd     xmm1,xmm5
    punpckldq   xmm1,xmm1
    psubq       xmm0,xmm1
    psubq       xmm6,xmm2
    psllq       xmm6,34h
    paddq       xmm0,xmm6
    ret
end _ultod3_int64
