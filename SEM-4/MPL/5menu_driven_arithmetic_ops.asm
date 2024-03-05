%macro rw 3
  mov rax, %1
  mov rdi, 01  
  mov rsi, %2
  mov rdx, %3 
  syscall
%endmacro

section .data
menu1 db "MENU: 1. Add  2. Subtract  3. Multiply  4. Divide  5. Exit"
len1 equ $-menu1

menu2 db "  Enter option: "
len2 equ $-menu2

num1 dq 0000000000000007h
num2 dq 0000000000000002h

section .bss
result  resb 1
asciiarr resb 1
count resb 2
choice resb 1

section .text
global _start
_start:

main:
    rw 01, menu1, len1
    rw 01, menu2, len2
    rw 00, choice, 02

    cmp byte[choice], 31h
    jz addition

    cmp byte[choice], 32h
    jz subtraction

    cmp byte [choice], 33h
    jz multiplication

    cmp byte [choice], 34h
    jz division
    
    cmp byte[choice], 35h
    jz exit

addition:
    mov rax, qword[num1]
    add rax, qword[num2]
    mov qword[result], rax
    call hta
    jmp main

subtraction:
    mov rax, qword[num1]
    sub rax, qword[num2]
    mov qword[result], rax
    call hta
    jmp main

division:
    xor rax, rax
    xor rcx, rcx
    xor rdx, rdx
    
    mov rax, qword[num1]
    mov ecx, dword[num2]
    div ecx  
    mov qword[result], rax
    call hta
    jmp main

multiplication:
    mov eax, dword[num1]
    mov ecx, dword[num2]
    mul ecx
    mov qword[result], rax
    call hta
    jmp main

exit:
    mov rax, 60
    xor rdi, rdi
    syscall

hta:
    mov rsi, asciiarr
    mov byte [count], 16
    mov rax, [result]

down:    
    rol rax, 04h
    mov bl, al
    and bl, 0fh
    cmp bl, 09h
    jbe next
    add bl, 07h

next:      
    add bl, 30h
    mov [rsi], bl
    inc rsi
    dec byte [count]
    jnz down

    ; Print the result
    rw 01, asciiarr, 0x10

    ret

