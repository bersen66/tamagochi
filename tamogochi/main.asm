
_main:
	LDI        R27, 255
	OUT        SPL+0, R27
	LDI        R27, 0
	OUT        SPL+1, R27

;main.c,1 :: 		void main()
;main.c,3 :: 		}
L_end_main:
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main
