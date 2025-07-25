;;
;; EPITECH PROJECT, 2025
;; Asembly
;; File description:
;; strlen
;;

BITS 64
SECTION .text ; define this section as code
GLOBAL strlen ; make my function accessible

strlen:
    PUSH RBP ; prologue
    MOV RBP, RSP ;prologue

    MOV RCX, 0 ;initialize counter a zero pour avoir la len
    MOV RDI, RDI ; initialization pointeur source
    MOV RAX, 0 ; initialize RAX a zero

loop:
    CMP BYTE [RDI], 0 ; compare le pointeur source a zero
    JE done ; si c'est zero alors on a fini
    INC RCX ; incrementer le counter
    INC RDI ; incrementer le pointeur source
    JMP loop ; jump to loop

done:
    MOV RAX, RCX ; mettre la valeur de counter dans RAX
    LEAVE ; epiloque
    RET ;return
