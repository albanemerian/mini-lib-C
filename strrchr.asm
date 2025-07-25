;;
;; EPITECH PROJECT, 2025
;; Asembly
;; File description:
;; strrchr
;;

BITS 64
SECTION .text
GLOBAL strrchr

strrchr:
    PUSH RBP ; prlogue de la funtion
    MOV RBP, RSP ; prologue de la fonction
    MOV RAX, 0            ; Initialize return value (NULL)
    MOV RDX, RDI          ; Keep a copy of the start of the string

loop:
    CMP BYTE [RDI], 0     ;  check si le string est nul ou fini
    JE done
    CMP BYTE [RDI], SIL   ; compare si le charectère actuel est égal à i
    JNE next               ; si non, on jump à next
    MOV RAX, RDI          ; Umettre a jour la valuer de reotur si trouvé

next:
    INC RDI               ; incrémenter la position et décaller le pointeur
    JMP loop

done:
    CMP sil, 0            ; cherhcer le \0 dans la string
    JNE exit
    MOV RAX, RDI          ; si trouvé, mettre à jour la valeur de retour

exit:
    LEAVE ; epilogue
    RET
