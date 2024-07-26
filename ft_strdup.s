BITS 64

section .text
    global ft_strdup
    extern ft_strlen
    extern ft_strcpy
    extern malloc

ft_strdup:
    push rdi
    call ft_strlen
    ;cmp rax, byte 0
    ;je _empty_str
    mov r9, rdi
    mov rdi, rax
    inc rdi
    call malloc
    cmp rax, byte 0
    je _empty_str
    mov rdi, rax
    mov rsi, r9
    call ft_strcpy
    pop rdi
    ret

_empty_str:
    xor rax, rax
    pop rdi
    ret