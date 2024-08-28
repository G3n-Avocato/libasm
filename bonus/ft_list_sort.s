BITS 64

section .text
    global ft_list_sort

ft_list_sort:
    push rbp
    mov rbp, rsp
    sub rsp, 16
    
_start:
    cmp rsi, 0                  ; check if fct cmp not NULL
    je _ret
    mov rbp, rdi         ; mov args fct list sort in rbp to free rdi & rsi
    mov rdx, rsi

_first_node:
    mov rdi, rbp
    mov r8, [rdi]              ; rec addr first node list
    cmp r8, 0                  ; check first node not NULL
    je _ret

_data_in_reg:
    mov rdi, qword [r8]
    mov r10, qword [r8 + 8]
    
    cmp r10, 0
    je _ret                     ; end list, exit fct
    
    mov rsi, qword [r10]

_call_fct:
    call rdx                    ; appel fct cmp 
    test rax, rax
    jle _continue               ; if inf/equal restart loop

    ;mov rsi, r8                ; rec addr next node 
    ;mov rdi, qword [r10 + 8]    ; rec addr next node
    ;mov qword [r8 + 8], rdi    ; swap r10 + 8
    ;mov qword [r10 + 8], r8    ; swap r8 + 8

    mov rsi, qword[r8]
    mov rdi, qword[r10]

    mov qword[r8], rdi
    mov qword[r10], rsi

    jmp _first_node

_continue:
    mov r8, r10
    jmp _data_in_reg

_ret:
    add rsp, 16
    pop rbp
    ret