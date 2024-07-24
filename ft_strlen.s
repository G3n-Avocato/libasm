BITS 64
section .text
    global ft_strlen
ft_strlen:
    push rdi
    xor rcx, rcx

_ft_strlen_loop:
    cmp [rdi], byte 0
    jz _ft_strlen_null
    inc rcx
    inc rdi
    jmp _ft_strlen_loop
_ft_strlen_null:
    mov rax, rcx
    pop rcx
    ret