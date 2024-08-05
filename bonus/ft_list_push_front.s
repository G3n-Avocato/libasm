BITS 64 

section .text
    global ft_list_push_front

; permet gestion propre de la pile, pour restaurer rbp
; acces au parametre et var locales, creer ou manipulation de node rbp peut etre utiliser pour acceder facilement au element sans perturber la pile
; convention d'appel 
ft_list_push_front:
    push rbp
    mov rbp, rsp
    