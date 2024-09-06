BITS 64

section .text
    global ft_strdup
    extern ft_strlen
    extern ft_strcpy
    extern malloc

ft_strdup:
    push rdi
    call ft_strlen
    mov rdi, rax
    inc rdi
    call malloc wrt ..plt
    cmp rax, byte 0
    je _empty_str
    mov rdi, rax
    pop rsi
    call ft_strcpy
    ret

_empty_str:
    xor rax, rax
    ret