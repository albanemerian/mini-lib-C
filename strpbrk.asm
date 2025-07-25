;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-NAN-4-1-asmminilibc-albane.merian
;; File description:
;; strpbrk
;;

BITS 64
SECTION .text
GLOBAL strpbrk

strpbrk:
    PUSH RBP        ; prologue
    MOV RBP, RSP    ; prologue 2
    MOV RAX, 0      ; initialiser RAX
    MOV RCX, 0      ; init le Frero RCX a zero
    MOV R8, 0       ; init le register libre R8 a zero
    MOV R9, 0      ;init le registre 9 a zero

loop: ; boocle de comparaison pour vérifier si nos some a la fin de str1
    CMP BYTE [RDI], 0 ; compare le byte str[i] a 0
    JE not_found ; si oui alors la str2 na pas été trouver et eturn NULL
    JMP loopextended ;sinon continuer la boucle de comparaison

loopextended: ; on réinitialise le pointer RSI et on met le pointer RDI dans R9
    XOR R8, R8  ; Remettre R8 a 0
    MOV R9B, BYTE[RDI] ; deplacer le byte de RDI dans R9

tesstloop: ; boucle de comparaison entre str1 et str2
    CMP BYTE [RSI + R8], 0   ; verifier si on est a la fin de str2
    JE increment ; si oui allors on incrmeent str2

    CMP R9B, BYTE[RSI + R8]; comparer les chracrtèere actuel des deux strogn
    JE found  ; si oui alors on a trouver le match

    INC R8  ; sino  on incremente le pointer R8
    JMP tesstloop ; et on relance la boucle de comapraison des stirng

increment: ; boucle d'incrémenation
    INC RDI
    JMP loop ; retourner dans la boucle de comparaison de str1

not_found: ; bouclez de not found return null
    MOV RAX, 0
    JMP done

found: ; boulce de found doonc le retrun value = un pointeur sur str1
    MOV RAX, RDI
    JMP done

done: ; epilogue
    LEAVE
    RET
