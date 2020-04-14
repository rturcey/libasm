section .text
        global  ft_list_size

ft_list_size:
        mov     rax, 0
        mov     r8, rdi

count:
        cmp     rdi, 0
        je      done
        inc     rax
        mov     rdi, [rdi + 8]
        jmp     count


done:
        mov     rdi, r8
        ret