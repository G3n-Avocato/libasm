BITS 64

section .text
        global ft_strcpy

ft_strcpy:
    push rdi
    push rsi
    xor rcx, rcx

_ft_strcpy_loop:
    mov dl, [rsi + rcx]
    mov [rdi + rcx], dl
    cmp dl, byte 0
    jz _src_null
    inc rcx
    jmp _ft_strcpy_loop

_src_null:
    mov rax, rdi
    pop rsi
    pop rdi
    ret
