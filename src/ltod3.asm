.686P
.MODEL FLAT, C
.CODE
.xmm

_ltod3:
;    mov         eax, ecx
;    sar         eax, 1Fh
;    cmp         eax, edx
;    jne         _ltod3_int64 (4013EDh)
; TODO - The above commented out code is present in the ltod3 normally used by 
; Visual Studio when targetting x86 with SSE2. It must be important.
    cvtsi2sd    xmm0, ecx
    ret 0
end _ltod3
