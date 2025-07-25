;;
;; EPITECH PROJECT, 2025
;; Asembly
;; File description:
;; strchr
;;

BITS 64
SECTION .text ; define le début de la section de code
GLOBAL strchr ; rendre ma fonction accessible

strchr:
    PUSH RBP ; prologue of the funciton
    MOV RBP, RSP ; prologue de la fonction


loop:
    CMP BYTE [RDI], SIL ; compare si le charactere est eagf a i
    JE done ; si oui, on jump a done
    CMP BYTE [RDI], 0 ; check si la stirng est nul ou fini
    JE not_found ;si oui alros not found
    INC RDI ; incrémenter le ptr dans la string
    JNE loop ; jump to loop

done:
    MOV RAX, RDI ; mettre la valeur de RDI dans RAX
    LEAVE ; epilogue
    RET ; return

not_found:
    MOV RAX, 0 ; return NULL if character is not found
    LEAVE ; epilogue
    RET ; return

