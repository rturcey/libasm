section	.text
		global	ft_list_remove_if
        extern  free

ft_list_remove_if:
        cmp     rdi, 0
        je      done
        cmp     rdx, 0          ; rdx = arg3
        je      done
        cmp     rcx, 0          ; rcx = arg4
        je      done
        jmp     first

remove_first:
        mov	r8, [rdi]
	mov	r9, [r8 + 8]
        push    rdi
        push    rsi
        push    rdx
        push    rcx
        push    r8
        push    r9
        mov     rdi, [r8]
        call    rcx
        pop     rdi
        push    rdi
        mov     rdi, r8
        call    free
        pop     r9
        pop     r8
        pop     rcx
        pop     rdx
        pop     rsi
        pop     rdi
        mov     [rdi], r9

first:
        mov     r8, [rdi]
        cmp     r8, 0
        je      done
        push    rdi
        push    rsi
        push    rdx
        push    rcx
        mov     rdi, [r8]
        call    rdx
        pop     rcx
        pop     rdx
        pop     rsi
        pop     rdi
        cmp     rax, 0
        je      remove_first
        mov     r8, [rdi]
        jmp     compare

remove:
        mov	rdi, r9
        mov     r9, [r9 + 8]
        mov     [r8 + 8], r9
        mov     r10, rdi
        push    rdi
        push    rsi
        push    rdx
        push    rcx
        push    r8
        push    r9
        mov     rdi, [rdi]
        call    rcx
        pop     rdi
        mov     rdi, r10
        push    rdi
        call    free
        pop     r9
        pop     r8
        pop     rcx
        pop     rdx
        pop     rsi
        pop     rdi

compare:
        mov     r9, [r8 + 8]
        cmp     r8, 0
        je      done
        cmp     r9, 0
        je      done
        push    rdi
        push    rsi
        push    rdx
        push    rcx
        push    r8
        push    r9
        mov     rdi, [r9]
        call    rdx
        pop     r9
        pop     r8
        pop     rcx
        pop     rdx
        pop     rsi
        pop     rdi
        cmp     rax, 0
        je      remove
        mov     r8, r9
        jmp     compare
done:
        ret