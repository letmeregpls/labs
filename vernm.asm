  section .data
	request db 'your message is', 10
	lenreq equ $-request
	keyreq db 'enter the key', 10
	lenkey equ $-keyreq
	modreq db 'choose the operation mode', 10
	lenmod equ $-modreq
	msg db 'hello world'
	len equ $-msg
	w db 'wrong operation mod'
	lenw equ $-w
	p db '',10
  	  	
  section .bss
	chiffre resb 255
	key resb 255
	opmod resb 1
  	
  section .text
  global _start
  _start:

	mov eax, 4				;message
	mov ebx, 1
	mov ecx, request
	mov edx, lenreq
	int 80h
	mov eax, 4				
	mov ebx, 1
	mov ecx, msg
	mov edx, len
	int 80h
	mov eax, 4				
	mov ebx, 1
	mov ecx, p
	mov edx, 1
	int 80h

	mov eax, 4				;key request
	mov ebx, 1
	mov ecx, keyreq
	mov edx, lenkey
	int 80h
	
	mov eax, 3				;key input
	mov ebx, 0
	mov ecx, key
	mov edx, 255
	int 80h

	mov eax, 4				;operation mod request
	mov ebx, 1
	mov ecx, modreq
	mov edx, lenmod
	int 80h
	
	mov eax, 3				;operation mod input
	mov ebx, 0
	mov ecx, opmod
	mov edx, 1
	int 80h

  	mov ebp, msg
  	mov edi, chiffre
  	mov esi, key
	mov ebx, 26
  	mov ecx, len
  	
	_basecycle:					;space check
  	mov edx, 32
  	mov al, [ebp]
  	cmp edx, eax 
  	jz _cycleforspace

	mov edx, 100
	cmp edx, [opmod]			;encrypt/decrypt condition
  	je _cyclefordecription

	mov edx, 101
	cmp edx, [opmod]
	je _cycleforencryption
	jne _wrong
	

  _cycleforencryption:
  	sub al, 97
	mov dl, [esi]
	sub dl, 97
  	add al, dl
	div bl
  	add ah, 97
  	jmp _cycle2

 _cyclefordecription:
  	sub al, 97
	mov dl, [esi]
	sub dl, 97
	add al, 26
  	sub al, dl
	div bl
  	add ah, 97
  	jmp _cycle2
  
 _cycleforspace:
 	mov [edi], al
 	xor ah, ah
 	inc ebp
 	inc edi
	inc esi
 	sub ecx, 1
 	jmp _basecycle
 
 _cycle2:
  	mov[edi], ah
  	xor ah, ah
  	inc ebp
	inc esi
  	inc edi
  	loop _basecycle
	
	mov edx, len
  	mov ecx, chiffre
  	mov ebx, 1 
  	mov eax, 4
  	int 80h

	jmp _finish

 _wrong:
	mov edx, lenw
  	mov ecx, w
  	mov ebx, 1 
  	mov eax, 4
  	int 80h

 _finish:

  	mov eax, 1
  	int 80h 	
