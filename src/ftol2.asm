.586
.MODEL FLAT, C
.CODE
.xmm


; Convert double to 32-bit int.
; When building for 32-bit x86, with or without SSE enabled, the
; compiler will generate calls to _ftol2_sse and _ftol2. I don't
; understand why or what it thinks the difference is.

_ftol2_sse PROC NEAR;
   jmp _ftol2
   
   ; Other resources I found online say the code below should work, but it
   ; doesn't. I don't know why.
;   push ebp
;   mov ebp, esp
;   cvttsd2si eax, QWORD PTR [ebp+8]
;   pop ebp
;   ret 0
_ftol2_sse ENDP


; The input is in st(0), ie the x87 stack.
_ftol2 PROC NEAR;
	push  ebp
	mov   ebp, esp
	sub   esp, 20h
	and   esp, 0fffffff0h
	fistp dword ptr [esp + 10h]
	mov   eax, dword ptr [esp+10h]
	leave
	ret 0
_ftol2 ENDP

END
