BITS 64

section .text
        global ft_strcmp

ft_strcmp:
    push rdi
    push rsi
    xor rcx, rcx

_ft_strcmp_loop:
    mov al, byte[rdi]
    mov bl, byte[rsi]
    cmp al, 0
    je _s2_test
    cmp bl, 0
    je _s1_sup
    cmp al, bl
    jne _not_equal
    inc rdi
    inc rsi
    jmp _ft_strcmp_loop

_s2_test:
    cmp bl, 0
    je _equal
    jmp _s2_sup

_not_equal: 
    jg _s1_sup
    jmp _s2_sup

_s1_sup:
    mov rax, 1
    jmp _ft_end

_s2_sup:
    mov rax, -1
    jmp _ft_end

_equal:
    mov rax, 0

_ft_end:
    pop rsi
    pop rdi
    ret