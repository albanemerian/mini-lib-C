;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-NAN-4-1-asmminilibc-albane.merian
;; File description:
;; strstr
;;

BITS 64
SECTION .text
GLOBAL strstr

strstr:
    PUSH RBP            ; prologue
    MOV RBP, RSP        ; prologue 2

    MOV RAX, 0


    CMP BYTE [RSI], 0   ; verifier que l'aifguile n'est pas vide
    JE .empty_needle    ; si vide alors retourner la chaine de caractere

    CMP BYTE [RDI], 0   ; verifier que la string n'est pas vide
    JE .not_found       ; si vide alors retourner 0
   ; MOV RAX, RDI        ; enregistrer l'adresse de début de le stirng

.inc:
    MOV RCX, RDI
    MOV RDX, RSI

.compare:
    MOV AL, BYTE [RDX]        ; récupérer le charactère actuel des str's
    CMP AL, 0
    JE .found
    MOV BL, BYTE [RCX]       ; récupérer le charactère actuel des str's
    CMP BL, 0           ; regader si on est a la fin de st2
    JE .not_found           ; Si oui bah on a trouver la phrase
    CMP AL, BL          ; compare les deux char a l'infex
    JNE .next_char      ; si les char ne sont pas pareil alors au suivant

    INC RDX              ; incrementer le ptr des string
    INC RCX             ; incrementer le ptr des string
    JMP .compare        ; relancer la boucle

.next_char:
    INC RDI             ; allér au charactere d'apres
    CMP BYTE [RDI], 0   ; regarder si on est a la fin de la string
    JE .not_found       ; si on est a la fin alors on a pas trouver la phrase
    JMP .inc           ; et relancer la loop

.found:
    MOV RAX, RDI        ; retourner l'adresse de la string
    LEAVE               ; Epilogue
    RET                 ; Return

.empty_needle:
    MOV RAX, RDI        ; si la string est vide alsor etourner la string
    LEAVE
    RET


.not_found:
    MOV RAX, 0       ; retourner 0 si la str a pas été trouver
    LEAVE
    RET

