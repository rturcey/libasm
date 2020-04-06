section .text
        global  ft_strdup
        extern  malloc
        extern  ft_strlen
        extern  ft_strcpy

%ifidn __OUTPUT_FORMAT__, elf64
 %define PIC wrt ..plt
%else
 %define PIC
%endif

ft_strdup:
        mov     rax, 0
        cmp     rdi, 0
        je      done
        call    ft_strlen
        add     rax, 1
        push    rdi
        mov     rdi, rax
        call    malloc PIC
        cmp     rax, 0
        je      done
        pop     rdi
        mov     rsi, rdi
        mov     rdi, rax
        call    ft_strcpy

done:
        ret

