section .text
    global print_str
    global print_int
    global print_char


print_int:
    push ebp
    mov ebp, esp
    sub esp, 32

    pushad

    mov eax, [ebp+8]
    cmp eax, 0             
    jnl .positive
    neg eax

    push dword '-'
    call print_char
    add esp, 4

    .positive:

    xor esi, esi          
    mov ecx, 10
    .itoc:                
        xor edx, edx
        div ecx           
        add dl, '0'
        lea edi, [ebp-4+32-1]
        sub edi, esi
        mov [edi], dl

        inc esi            

        cmp eax, 0
        jle .break
    jmp .itoc
    .break:

    lea edi, [ebp-4+32]
    sub edi, esi
    
    push esi
    push edi
    call print_str
    add esp, 8
    
    popad

    mov esp, ebp
    pop ebp
    ret



print_str:
	push ebp
	mov ebp, esp

    pushad

	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, [ebp+8]
	mov edx, [ebp+12]
	int 0x80

	popad

	pop ebp
	ret



print_char:
	push ebp
	mov ebp, esp

    pushad

	mov eax, 0x4
	mov ebx, 0x1
	lea ecx, [ebp+8]
	mov edx, 0x1
	int 0x80

	popad

	pop ebp
	ret