BITS 64

section .text
    global ft_write
    extern __errno_location

ft_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jl _error
    ret

_error:
    neg rax
    push rax
    call __errno_location wrt ..plt
    pop rdx
    mov [rax], rdx
    mov rax, -1
    ret