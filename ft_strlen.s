BITS 64
section .note.GNU-stack noalloc noexec nowrite progbits
section .text
    global ft_strlen
ft_strlen:
    mov rdi, [rsp + 4]
    push rcx
    xor rcx, rcx
    call _ft_strlen_loop

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