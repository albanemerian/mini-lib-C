;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-NAN-4-1-asmminilibc-albane.merian
;; File description:
;; strncmp
;;

BITS 64
SECTION .text
GLOBAL strncmp


strncmp:
    PUSH RBP        ; prologue
    MOV RBP, RSP    ; prologue 2

    XOR RCX, RCX ; initialiser counter
    XOR RAX, RAX ; initialiser RAX
    XOR R8, R8 ; initialiser R8 R8 byte zero

loop:
    MOV AL, BYTE [RDI + RCX] ; récuper le charectere de str1
    MOV R8B, BYTE [RSI + RCX] ; récuper le charectere de str2

    CMP RCX, RDX ; comparer l'état du conteur avec la len de la string
    JE equal

    CMP R8, 0 ; regarder si str2 est null
    JE not_equal

    CMP AL, R8B ; comparer les deux charzcteres a pos
    JNE not_equal ; si les str ne sont pas egale aller dans la fonctions != et soustraire

    CMP RAX, 0 ; regarder si str1 est null
    JE not_equal ; si str1 est null alors aller dans la fonction != et soustraire

    INC RCX ; incrementer le counter
    JMP loop ; repéter la boucle

not_equal:
	SUB	AL, R8B
	MOVSX	RAX, AL
    JMP done  ; aller a la lfin

equal:
    MOV RAX, 0    ; string est egale donc retourne 0
    JMP done

done:
    LEAVE
    RET

