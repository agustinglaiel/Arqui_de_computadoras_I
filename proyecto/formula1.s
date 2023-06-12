//FUNCION FORMULA 1 
.text
.global formula1

formula1:
    MOV     R0, #2
    MOV     SP, #pilaptr
    BL      F1
    B       Termino

F1:
    STMFD   SP!, {R4, R5, R6, R7, LR}
    MOV     R4, #0x80
    MOV     R5, #1

ForFormula1:
    MOV     R0, R4
    BL      Display
    MOV     R0, R6
    BL      Retardo
    BL      SystemCLS
    
    CMP     R4, #0x80
    MOVEQ   R4, #0xC0
    MOVNE   R4, R4, LSR #1

    CMP     R4, #0xFF
    BNE     ForFormula1

ResetBits:
    MOV     R0, R4
    BL      Display
    MOV     R0, #1500
    BL      Retardo
    MOV     R4, #0x00
    B       ForFormula1

Display:
    MOV     R7, #0x80
forDisplay:
    TST     R4, R7
    MOV     R0, R4
    MOVS    R7, R7, LSR #1
    BNE     forDisplay
    MOV     PC, LR

Retardo:
    SUBS    R0, R0, #1
    BNE     Retardo
    MOV     PC, LR

SystemCLS:
    MOV     PC, LR

Termino:
    LDMFD   SP!, {R4, R5, R6, R7, LR}
    MOV     PC, LR

.section .data
pilaptr:
    .word       1

.section .bss
.comm pila, 40
