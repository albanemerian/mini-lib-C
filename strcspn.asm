;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-NAN-4-1-asmminilibc-albane.merian
;; File description:
;; strcspn
;;


BITS 64
SECTION .text
GLOBAL strcspn

strcspn:
    PUSH RBP        ; prologue
    MOV RBP, RSP    ; prologue 2
    MOV RAX, 0      ; initialiser RAX
    MOV RCX, 0 ; init le Frero RCX a zero
    MOV R8, 0 ;init le register libre r_ a zero
    MOV R9, 0 ; init le register R9 a zero car il est libre

loop: ; verifie si on est a la fin de la str1 si oui fin si non on va a la comparaison des charactère
    CMP BYTE [RDI], 0 ; regarder si la string est fini
    JE done ; si oui alors aller a la fin
    JMP loopextended ; sinon continuer la boucle de comparaison

continue: ;on incrémente le str1[i] et on relance la verification de str1
    INC RDI ; incrementer le pointer RDI
    JMP loop ;relancer la boucle

increment:; on incrémente le str2[i] et on relance la verification de str1
    INC RCX ; incrementer le pointeur rcx
    JMP continue ; retrouner a la fonction continue pour incrementer le pointer RDI

loopextended: ; on réinitialise le pointer RSI et on met le pointer RDI dans R9
    XOR R8, R8 ;réinitialiser le pointer R8
    MOV R9B, BYTE[RDI] ; mettre le charactere dans la string

tesstloop: ; compare chaque carachtère de la string 1 avec la string 2
    CMP BYTE [RSI + R8], 0; comparer le character actuel de RSI avec 0
    JE increment ; oui ces la fin donc on incrément

    cmp R9B, BYTE[RSI + R8] ; compare le caractere actule de str1 a str2
    JE done ; si les caractere sont les meme alors on a fini

    INC R8 ; sinon on incremente le pointer R8
    JMP tesstloop ; et on recomence
done:
    MOV RAX, RCX ; mettre la valuer du conteur RCX dans RAX
    LEAVE ; epilogue
    RET ; return
