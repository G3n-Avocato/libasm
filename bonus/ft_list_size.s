BITS 64

section .text
    global ft_list_size

ft_list_size:
    push rbp
    mov rbp, rsp
    sub rsp, 16                 ; fais de la place sur la stack
    xor rax, rax                ; rax = 0
    cmp rdi, 0                  ; check first node if NULL
    je _ret
    inc rax                     ; +1

_loop:

    mov rbx, qword [rdi + 8]    ; rec addr next node
    cmp rbx, 0                  ; check if NULL
    je _ret
    inc rax                     ; +1
    mov rdi, rbx                ; mov addr next node in rdi
    jmp _loop

_ret:
    add rsp, 16                 ; restore stack
    pop rbp
    ret
