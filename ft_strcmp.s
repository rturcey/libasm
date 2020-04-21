section .text
        global ft_strcmp

ft_strcmp:
        mov     rcx, 0
        mov     rax, 0

compare:
        mov     dl, [rsi]
        cmp     dl, 0
        je      done
        cmp     [rdi], dl
        jne     done
        inc     rsi
        inc     rdi
        jmp     compare
done:
        mov     al, [rdi]
        mov     dl, [rsi]
        sub     rax, rdx
        ret