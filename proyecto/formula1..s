//FUNCION FORMULA 1 


.global formula1
formula1:
    MOV     R0, #2 
    MOV     SP, #pilaptr
    BL      Formula1
    end

Formula1
    STMFD   SP!, {R4, R5, R6, R7, LR} ; Almaceno los registros en la pila
    MOV     R4, #0x00 ; Inicializo R4 con 00000000
    MOV     R5, #1     ; Inicializo R5 con el bit más a la izquierda (R5 = 1 en la primera iteración)

ForFormula1
    MOV     R0, R4 
    BL      Display
    MOV     R0, R6 
    BL      Retardo
    BL      SystemCLS
    ORR     R4, R4, R5 ; Cambio el bit actual de 0 a 1
    MOV     R6, R5     ; Guardo el valor anterior de R5 en R6
    MOV     R5, R5, LSL #1 ; Desplazo R5 hacia la izquierda para cambiar al siguiente bit
    SUBS    R7, R7, #1 ; R7 es un contador para controlar las iteraciones
    BEQ     ResetBits  ; Si R7 = 0, todos los bits están en 1, vamos a ResetBits
    BNE     ForFormula1

ResetBits
    MOV     R0, R4     ; Pasamos el valor actual de R4 a R0
    BL      Display    ; Mostramos el valor actual de R4
    MOV     R0, #1500  ; Tiempo de pausa en milisegundos (1500 ms = 1,5 segundos)
    BL      Retardo    ; Pausa durante 1,5 segundos
    MOV     R4, #0x00  ; Reseteamos todos los bits de R4 a 0
    B       ForFormula1 ; Volvemos al bucle principal

Display
    MOV     R7, #0x80
forDisplay
    TST     R4, R7
    MOVEQ   R0, #0x2A
    MOVNE   R0, #0x5F
    MOVS    R7, R7, LSR #1
    BNE     forDisplay
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
