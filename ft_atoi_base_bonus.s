section .text
        global  ft_atoi_base
        extern  ft_strlen

ft_atoi_base:
        cmp     rdi, 0
        je      error
        cmp     rsi, 0
        je      error
        mov     r8, rdi
        mov     rdi, rsi
        call    ft_strlen
        cmp     rax, 1
        jbe     error
        mov     rdx, 0
        mov     rsi, rdi
        mov     rdi, r8
        mov     r8, 1                       ; nb sign
        mov     r9, rax                     ; base length
        mov     rax, 0
        jmp     check_base

reset:
        inc     rdx

check_base:
        cmp     byte[rsi + rdx], 0
        je      convert
        mov     rcx, rdx
        inc     rcx
        check_char:
                cmp     byte[rsi + rcx], 0
                je      reset
                mov     bl, byte[rsi + rcx]
                cmp     bl, byte[rsi + rdx]
                je      error
                cmp     bl, 43
                je      error
                cmp     bl, 45
                je      error
                cmp     bl, 9
                je      error
                cmp     bl, 10
                je      error
                cmp     bl, 11
                je      error
                cmp     bl, 12
                je      error
                cmp     bl, 13
                je      error
                cmp     bl, 32
                je      error
                inc     rcx
                jmp     check_char
        jmp     check_base

inc_rcx:
        inc     rcx
        jmp     skip_spaces

skip_plus:
        inc     rcx;
        jmp     skip_signs

mult_sign:
        imul    r8, -1
        inc     rcx
        jmp     skip_signs

convert:
        mov     rcx, 0
        skip_spaces:
                cmp     byte[rdi + rcx], 9
                je      inc_rcx
                cmp     byte[rdi + rcx], 10
                je      inc_rcx
                cmp     byte[rdi + rcx], 11
                je      inc_rcx
                cmp     byte[rdi + rcx], 12
                je      inc_rcx
                cmp     byte[rdi + rcx], 13
                je      inc_rcx
                cmp     byte[rdi + rcx], 32
                je      inc_rcx
        skip_signs:
                cmp     byte[rdi + rcx], 43
                je      skip_plus
                cmp     byte[rdi + rcx], 45
                je      mult_sign
                jmp     convertion
        inc_conv:       
                imul    rax, r9
                add     rax, rdx
                inc     rcx
        convertion:
                mov     bl, byte[rdi + rcx]
                cmp     bl, 0
                je      done
                mov     rdx, 0
                isin:
                        cmp     rdx, r9
                        je      done
                        cmp     bl, byte[rsi + rdx]
                        je      inc_conv
                        inc     rdx
                        jmp     isin

done:
        imul    rax, r8
        ret

error:
        mov     rax, 0
        ret