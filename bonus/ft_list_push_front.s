BITS 64 

section .text
    global ft_list_push_front
    extern malloc

ft_list_push_front:
    push rbp
    mov rbp, rsp

_alloc_node:
    sub rsp, 16                     ; do some space on stack

    mov [rbp - 16], rdi             ; mov node in stack
    mov [rbp - 8], rsi              ; mov data in stack

    mov rdi, 16
    call malloc wrt ..plt
    test rax, rax                   ; malloc is in rax
    je _null_malloc

    mov rdi, [rbp - 8]              ; get back data
    mov qword [rax], rdi            ; move data to malloc

    mov rbx, [rbp - 16]             ; get back head address
    mov rdi, [rbx]                  ; deference dans rdi 
    mov qword [rax + 8], rdi        ; head addr to malloc

    mov [rbx], rax                  ; move malloc at that address

_null_malloc:
    add rsp, 16
    pop rbp
    ret