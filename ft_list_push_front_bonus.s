section .text
        global  ft_list_push_front
        extern  malloc

ft_list_push_front:
        mov     rax, 0
        mov     r8, 0
        push    rdi
        push    rsi
        mov     rdi, 16
        call    malloc
        pop     rsi
        pop     rdi
        cmp     rax, 0
        je      done
        mov     [rax], rsi
        mov     r8, [rdi]
        mov     [rax + 8], r8
        mov     [rdi], rax


done:
        ret