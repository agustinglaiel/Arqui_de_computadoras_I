//FUNCION BONDI

.global bondi_asm
bondi_asm:
	PUSH	 {R4, R5, LR}
	MOV R4, #13
	LDR R5, =array
;
loop: LDRB R0, [R5], #1
	MOV R6, R0
	BL disp_binary
	MVN R0, R6
	BL leds
	MOV R0, #200;
	BL delay;
;
	SUBS R4, R4, #1;
	BNE loop
;
	POP {R4, R5, R6, PC} //RETURN FROM SUBROUTINE

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