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
    mov rbp, rdi                ; mov args fct list sort in rbp to free rdi & rsi
    mov r9, rsi

_first_node:
    mov rdi, rbp               ; recover addr list
    mov r8, [rdi]              ; rec first node himself
    cmp r8, 0                  ; check first node not NULL
    je _ret

_data_in_reg:
    mov rdi, qword [r8]         ; rec data 1 in first node 
    mov r10, qword [r8 + 8]     ; rec addr  for second node
    
    cmp r10, 0
    je _ret                     ; end list, exit fct
    
    mov rsi, qword [r10]        ; rec data 2 in second node

_call_fct:
    push r10                    ; push on stack val r10
    call r9                     ; appel fct cmp                
    test eax, eax
    pop r10
    jle _continue               ; if inf/equal restart loop

    mov rsi, qword[r8]          ; swap data content
    mov rdi, qword[r10]

    mov qword[r8], rdi
    mov qword[r10], rsi

    jmp _first_node

_continue:
    mov r8, r10                 ; mov +1 in node, a = b et b = c
    jmp _data_in_reg

_ret:
    add rsp, 16
    pop rbp
    ret