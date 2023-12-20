.586
.MODEL FLAT, C
.CODE
.xmm

_ftol2_sse PROC NEAR;
   ; Assume SSE support.
   push ebp
   mov ebp, esp
   cvttss2si eax, DWORD PTR 8[ebp]
   pop ebp
   ret 0
_ftol2_sse ENDP


_ftol2:
   jmp _ftol2_sse		;use the SSE2 implementation
end _ftol2
