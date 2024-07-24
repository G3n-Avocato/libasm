BITS 64

section .text
        global ft_strcpy

ft_strcpy:
    ;mov rdi, rsi
    mov rax, rsi
    ret