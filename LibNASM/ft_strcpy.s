global	_ft_strcpy

section .text
_ft_strcpy:
		xor rcx, rcx
.loop:
		cmp byte [rsi + rcx], 0
		je .return
		mov dl, byte [rsi + rcx]
		mov byte [rdi + rcx], dl
		inc rcx
		jmp .loop
.return:
		mov byte [rdi + rcx], 0
		mov rax, rdi
		ret
