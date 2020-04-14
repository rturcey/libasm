section	.text
		global	ft_list_sort

ft_list_sort:
        cmp		rdi, 0
		je		done
		cmp		rsi, 0
		je		done
		mov		r10, rdi
		mov		rdi, [rdi]
		mov		rbx, rsi
		jmp		sort

invert:
		mov		rax, [r8]
		mov		r9, [rdi]
		mov		[rdi], rax
		mov		[r8], r9
        mov     rdi, [r10]

sort:
		mov		r8, [rdi + 8]
		cmp		r8, 0
		je		done
		push	rdi
		mov		rsi, [r8]
		mov		rdi, [rdi]
		call	rbx
		pop		rdi
		cmp		eax, 0
		jg		invert
	    mov		rdi, [rdi + 8]
        jmp     sort

done:
		mov		rdi, r10
		ret