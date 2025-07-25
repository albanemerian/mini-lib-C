;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-NAN-4-1-asmminilibc-albane.merian
;; File description:
;; strcmp
;;

BITS 64
SECTION .text
GLOBAL strcmp ; Exported symbol for the function

strcmp:
    PUSH RBP            ; Prologue
    MOV RBP, RSP        ; prologue partie 2 :) 

.loop:
    MOV AL, [RDI]      ; récupérer les deux str's
    MOV BL, [RSI]      ; récupérer les deux str's

    CMP AL, BL         ; comparer les str
    JNE .not_equal      ; si les str ne sont pas egale aller dans la fonctions != et soustraire

    CMP AL, 0          ; vérifier si la str1 est a la fin
    JE .equal          ; si les string son egale aller dans la fonction equal

    INC RDI            ; incrémanter le pointer de la str
    INC RSI            ; incrémanter le pointer de la str
    JMP .loop          ; repéter la boucle

.not_equal:

    SUB AL, BL         ; soustraite la taile des deux string AL = AL(byte de str1) - BL(byte de str2)
    MOVSX RAX, AL      ; assign la valeur de al a RAX en prenant encompte le signe
    JMP .done          ; jump a la fi nde la fonction

.equal:
    MOV RAX, 0         ; string est egale donc retourne 0

.done:
    LEAVE            ; Epiloguei want my putchar function to have the 
    RET                 ; Return de la constion

; ^_^
;(°~°)
;('|')  doof doof le chat :)
