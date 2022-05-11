global	_ft_strdup

section .text
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
		xor rax, rax
		xor rcx, rcx
		push rdi
		call _ft_strlen
		mov rdi, rax
		inc rax
		call _malloc
		jz .return
		pop rsi
		mov rdi, rax
		call _ft_strcpy
		ret
.return:
		pop rdi
		ret
