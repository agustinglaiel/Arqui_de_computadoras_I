//autof.s 

// prj.s
// 23 de Mayo de 2022
// Arqui I UCC

.text

.global main
main:
      LDR R3, =array // load base address of a into R3
      ... more code here
done: NOP            // dummy instruction for breakpoint
      MOV NPC,L       // return from main

.data
array:
      .byte 0x08
      .byte 0x10
      .byte 0xFF
      ... more data here
.end


//ESTO DE ARRIBA ES LA PLANILLA CORREGIDA
//LO DE ABAJO FUNCIONES DEL PROFE QUE TENEMOS QUE CORREGIR CON LO DE ARRIBA


.global autof
autof:
	PUSH	 {R4, R5, LR}
	MOV R4, #15
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

//

.global choquef
choquef:
	PUSH {R4, R5, R6, LR}
	MOV R4, #8
	LDR R5, =choque
;
ciclo: LDRB R6, [R5], #1
		MOV R0, R6
		BL disp_binary
		MVN R0,R6
		BL leds
		MOV R0, #200;
		BL delayMillis;
;
		SUBS R4, R4, #1;
		BNE ciclo
;
		POP {R4, R5, R6, PC}


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

.end


//FUNCION FORMULA 1 (CREEMOS QUE ESTA)

MOV     r0, #2 
MOV     SP, #pilaptr
BL      BateriaBaja
end

BateriaBaja
    STMFD   SP!, {r4, r5, r6, r7, LR} ; Almaceno los registros en la pila
    MOV     r6, r0 
    MOV     r4, #0x01 ; Inicializo r4 con 00000001

ForBateriaBaja
    MOV     r0, r4 
    BL      Display
    MOV     r0, r6 
    BL      Retardo
    ; MOV r0, "cls" por si la función system usara parámetros
    BL      SystemCLS
    MOV     r4, r4, LSL #1 ; Desplazo los bits hacia la izquierda
    SUBS    r5, r5, #1
    BNE     ForBateriaBaja
    BEQ     Termino

Display
    ; STMFD SP!, {r4, r5, r6, r7}
    ; MOV     r7, #0x80 
    ; MOV     r4, r0
    forDisplay
    ; TST     r4, r7
    ; MOVEQ   r0, #0x5F
    ; MOVNE   r0, #0x2A
    ; MOVS    r7, r7, LSR #1
    ; BNE     forDisplay
    ; LDMFD   SP!, {r4, r5, r6, r7}
    MOV     PC, LR

Retardo
    SUBS    r0, r0, #1
    BNE     Retardo
    MOV     PC, LR

SystemCLS
    ; Simulo la limpieza de pantalla
    MOV     PC, LR

Termino
    LDMFD   SP!, {r4, r5, r6, r7, LR}
    MOV     PC, LR

pila        FILL        40
pilaptr     DCB         1