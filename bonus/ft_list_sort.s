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
    mov [rbp - 16], rdi         ; mov args fct list sort in rbp to free rdi & rsi
    mov [rbp - 8], rsi

_first_node:
    mov rdi, [rbp - 16]
    mov rbx, [rdi]              ; rec addr first node list
    cmp rbx, 0                  ; check first node not NULL
    je _ret

_data_in_reg:
    mov rdi, qword [rbx]
    mov r10, qword [rbx + 8]
    
    cmp r10, 0
    je _ret                     ; end list, exit fct
    
    mov rsi, qword [r10]

_call_fct:
    call qword [rbp - 8]    ; appel fct cmp 
    test rax, rax
    jbe _continue               ; if inf/equal restart loop
    
    mov qword [rbx], rsi        ; if sup, swap rdi & rsi in node list
    mov qword [r10], rdi
    jmp _first_node

_continue:
    mov rbx, r10
    jmp _data_in_reg

_ret:
    add rsp, 16
    pop rbp
    ret