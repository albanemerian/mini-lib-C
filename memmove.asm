;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-NAN-4-1-asmminilibc-albane.merian
;; File description:
;; memmove
;;
BITS 64
SECTION .text
GLOBAL memmove

memmove:
    PUSH RBP        ; Prologue
    MOV RBP, RSP    ; Prologue 2
    MOV RAX, RDI           ; garder en mémoire le pointeur de destination
    CMP RDI, 0            ; regarder si une des str est vide
    JE .return              ; if oui jump a la fin

    CMP RSI, 0            ;  regarder si l'autre str est vide
    JE .return       ; si oui alors jump la fin

    CMP RDX, 0            ; regarder si la taille est 0
    JE .return          ;si oui alors a la fin

    CMP RDI, RSI          ; Comparer les deux adresse actuel
    JE .return            ; Si elle sont égale alors on fait rien (gestion overlap)

    MOV RCX, RDX          ; mettre la taille dans RCX

    CMP RDI, RSI          ; comparer les deux adresse actuel
    JA .copy_backwards    ; si dest > src, alors la boucle de copie ce fait a l'envers

.copy_forwards:    ; boucle de copie "normal"
    MOV DL, [RSI]         ; récupérer le byte actuel
    MOV [RDI], DL         ; le sauvegarder dans la destination
    INC RSI               ; Incrémenter le pointeur source
    INC RDI               ; Incrémenter le pointeur destination
    DEC RCX               ; décrémentter  le counteur
    JNZ .copy_forwards    ; Continue if not done
    JMP .return       ; si non c'est la fin des haricots

.copy_backwards:     ; boucle de copie inverser
    ADD RSI, RCX          ; déplacer le pointeur source a la fin
    ADD RDI, RCX        ; déplacer le pointeur destination a la fin
    DEC RSI               ; ajuster
    DEC RDI

.backwards_loop:
    MOV DL, [RSI]         ; récupérer le byte actuel
    MOV [RDI], DL         ; le sauvegarder dans la destination
    DEC RSI              ; Déplacer le pointeur source a la fin
    DEC RDI              ; Déplacer le pointeur destination a la fin
    DEC RCX         ;decrémenter le counteur
    JNZ .backwards_loop    ;  si le contdur est pas zero alors on contines

.return:
    LEAVE
    RET
