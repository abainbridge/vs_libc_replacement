.586
.MODEL FLAT, C
.CODE

; The x86 instruction-set has no 64-bit x 64-bit multiply instruction,
; so the compiler inserts a call to this function.
;
; The standard Visual Studio implementation is 48 bytes long. This one
; is 31. Comically, the VS version includes conditional branches,
; presumably because that was an optimization on a 80386. Annoyingly
; the overhead to the caller to call this function is about 39 bytes.
; The compiler really should inline this function, but it never does.
;
; Let's call the 64-bit input params A and B. We deal with them in
; 32-bit chunks: AL, AH, BL, BH.
;
; The result we want is the bottom 64 bits of A x B. That is given by:
;   AL * BL + ((AL * BH) << 32) + ((BL * AH) << 32)
;
; Input params are on the stack:
;   ESP+8   AH
;   ESP+12  AL
;   ESP+16  BH
;   ESP+20  BL
;
; The result is in registers:
;   EDX - High
;   EAX - Low

_allmul PROC NEAR USES ESI;
    mov     ecx, dword ptr [esp + 16]
    mov     esi, dword ptr [esp + 8]
    mov     eax, ecx
    imul    ecx, dword ptr [esp + 12]
    mul     esi
    imul    esi, dword ptr [esp + 20]
    add     edx, ecx
    add     edx, esi
    ret     16
_allmul ENDP

END
