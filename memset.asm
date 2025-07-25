;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-NAN-4-1-asmminilibc-albane.merian
;; File description:
;; memset
;;

BITS 64
SECTION .text
GLOBAL memset

memset:
    PUSH RBP        ; prologue
    MOV RBP, RSP    ; prologue
    MOV RAX, RDI    ; mettre le pointeur dans RAX
    XOR RCX, RCX

loop:
    CMP RCX, RDX ; regarder si la len est null
    JE done ; si oui alors aller a la fin

    MOV BYTE [RDI], SIL ; mettre le charactere dans la string
    INC RDI ; incrementer le pointeur
    DEC RDX ; decrementer la len
    JMP loop ; repeter la boucle

done:
    LEAVE
    RET
