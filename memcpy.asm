;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-NAN-4-1-asmminilibc-albane.merian
;;; File description:
;;; memcpy
;;;
;
BITS 64
SECTION .text
GLOBAL memcpy

memcpy:
    PUSH RBP         ; prologue
    MOV RBP, RSP     ; prologue 2
    MOV RAX, RDI       ; garder en mémoire le pointeur de destination
    CMP RDI, 0       ; check if dest is NULL
    JE done
    CMP RSI, 0       ; check if src is NULL
    JE done
    CMP RDX, 0       ; check if len is 0
    JE done


loop:
    CMP RDX, 0       ; check if len is 0
    JE done          ; if len == 0, exit loop

    MOV BL, BYTE [RSI] ; copy one byte from src to BL
    MOV BYTE [RDI], BL ; copy one byte from BL to dest
    INC RDI           ; increment dest pointer
    INC RSI           ; increment src pointer
    DEC RDX           ; decrement len
    JMP loop          ; repeat loop

done:
    LEAVE
    RET
