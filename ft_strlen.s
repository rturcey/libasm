section .text
        global ft_strlen

ft_strlen:
        mov     rax, 0

count_len:
        cmp     byte [rdi + rax], 0
        je      done
        inc     rax
        jmp     count_len

done:
        ret