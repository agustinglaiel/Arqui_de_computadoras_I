//FUNCION BONDI

.global bondi
bondi:
	PUSH	 {R4, R5, LR}
	MOV R4, #13
	LDR R5, =array
;
loop: LDBR R0, [R5], #1
	MOV R0, R6
	BL disp_binary
	MVN R0, R6
	BL leds
	MOV R0, #300;
	BL delayMillis;
;
	SUBS R4, R4, #1;
	BNE loop
;
	POP {R4, R5, R6, PC} //RETURN FROM SUBROUTINE

//FUNCION FORMULA 1 

.global formula1
formula1:
    MOV     R0, #2 
    MOV     SP, #pilaptr
    BL      Formula1
    end

Formula1
    STMFD   SP!, {R4, R5, R6,R7, LR} ; Almaceno los registros en la pila
    MOV     R6, R0 
    MOV     R4, #0x01 ; Inicializo R4 con 10000000

ForFormula1
    MOV     R0, R4 
    BL      Display
    MOV     R0, R6 
    BL      Retardo
    ; MOV r0, "cls" por si la función system usara parámetros
    BL      SystemCLS
    MOV     R4, R4, LSL #1 ; Desplazo los bits hacia la izquierda
    SUBS    R5, R5, #1
    BNE     ForFormula1
    BEQ     Termino

Display
    ; STMFD SP!, {R4, R5, R6, R7}
    ; MOV     R7, #0x80 
    ; MOV     R4, R0
    forDisplay
    ; TST     R4, R7
    ; MOVEQ   R0, #0x5F
    ; MOVNE   R0, #0x2A
    ; MOVS    R7, R7, LSR #1
    ; BNE     forDisplay
    ; LDMFD   SP!, {R4, R5, R6, R7}
    MOV     PC, LR

Retardo
    SUBS    R0, R0, #1
    BNE     Retardo
    MOV     PC, LR

SystemCLS
    ; Simulo la limpieza de pantalla
    MOV     PC, LR

Termino
    LDMFD   SP!, {R4, R5, R6, R7, LR}
    MOV     PC, LR

pila        FILL        40
pilaptr     DCB         1

.data
array:
	.byte 0x80
	.byte 0xC0
	.byte 0xE0
	.byte 0xF0
	.byte 0xB8
	.byte 0x9C
	.byte 0x4E
	.byte 0x27
	.byte 0x13
	.byte 0x09
	.byte 0x04
    .byte 0x02
    .byte 0x01

.end