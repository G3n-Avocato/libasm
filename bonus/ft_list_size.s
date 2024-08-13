BITS 64

section .text
    global ft_list_size

ft_list_size:
    push rbp
    mov rbp, rsp
    sub rsp, 16
    xor rax, rax
    cmp rdi, 0
    je _ret
    inc rax

_loop:

    mov rbx, qword [rdi + 8]
    cmp rbx, 0
    je _ret
    inc rax
    mov rdi, rbx
    jmp _loop

_ret:
    add rsp, 16
    pop rbp
    ret
