;;
;; EPITECH PROJECT, 2025
;; Asembly
;; File description:
;; putchar
;;

BITS 64
SECTION .text ; define le début de la section de code
GLOBAL putchar ; rendre ma fonction accessible

putchar:
    PUSH RBP ; prologue
    MOV RBP, RSP ; prologue
    MOVZX EAX, DIL  ; Move the character from dil (8-bit) to EAX (32-bit) with zero extension

    ; Prepare for the write system call
    MOV EDI, 1      ; File descriptor 1 (stdout)
    sub RSP, 8      ; Allocate space on the stack
    MOV [RSP], al   ; Store the character on the stack
    MOV RSI, RSP    ; Buffer (address of the character on the stack)
    MOV RDX, 1      ; Number of bytes to write (1 byte)
    MOV EAX, 1      ; System call number for write (sys_write)
    syscall         ; Perform the system call

    ; Restore the character to eax (return value)
    MOVZX eax, byte [RSP]

    LEAVE    ;epilogue
    RET  ;return
