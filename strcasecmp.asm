;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-NAN-4-1-asmminilibc-albane.merian
;; File description:
;; strcasecmp
;;
BITS 64
SECTION .text
GLOBAL strcasecmp

strcasecmp:
    PUSH RBP            ; Prologue
    MOV RBP, RSP        ; prologue partie 2 :)

.loop:
    MOV AL, [RDI]      ; récupérer les deux char's
    MOV BL, [RSI]      ; récupérer les deux char's

    ; comparer le char AL en minuscule si c'est en majuscule
    CMP AL, 'A'
    JB .check_BL
    CMP AL, 'Z'
    JA .check_BL
    ADD AL, 32

.check_BL:
    ; comparer le char de BL en minuscule si c'est en majuscule
    CMP BL, 'A'
    JB .compare
    CMP BL, 'Z'
    JA .compare
    ADD BL, 32

.compare:
    CMP AL, BL         ; comparer les str

    JG .is_lower       ; si les str ne sont pas egale aller dans la fonctions != et soustraire
    JL .is_upper

    CMP AL, 0          ; vérifier si la str1 est a la fin
    JE .equal          ; si les string son egale aller dans la fonction equal

    INC RDI            ; incrémanter le pointer de la str
    INC RSI            ; incrémanter le pointer de la str
    JMP .loop

.is_lower:
    SUB AL, BL         ; soustraite la taile des deux string AL = AL(byte de str1) - BL(byte de str2)
    MOVSX RAX, AL      ; assign la valeur de al a RAX en prenant encompte le signe
    JMP .done          ; jump a la fi nde la fonction

.is_upper:
    SUB AL, BL         ; soustraite la taile des deux string AL = AL(byte de str1) - BL(byte de str2)
    MOVSX RAX, AL      ; assign la valeur de al a RAX en prenant encompte le signe
    JMP .done

.equal:
    MOV RAX, 0         ; string est egale donc retourne 0

.done:
    LEAVE              ; Epilogue
    RET                ; Return de la constion

; ^_^
;(°~°)
;('|')  doof doof le chat :)
