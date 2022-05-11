global	_ft_strcmp

section .text
_ft_strcmp:
		xor rcx, rcx
		xor rdx, rdx
		xor rax, rax
.loop:
		mov dl, byte [rdi + rcx]
		mov al, byte [rsi + rcx]
		cmp dl, 0
		je .return
		cmp al, 0
		je .return
		cmp dl, al
		jne .return
		inc rcx
		jmp .loop
.return:
		sub rdx, rax
		mov rax, rdx
		ret
