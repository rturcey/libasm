section .text
        global ft_strcpy

ft_strcpy:
        mov     rcx, 0

copy:
        mov     dl, byte [rsi + rcx]
        mov     byte [rdi + rcx], dl
        cmp     dl, 0
        je      done
        inc     rcx
        jmp     copy

done:
        mov     rax, rdi
        ret