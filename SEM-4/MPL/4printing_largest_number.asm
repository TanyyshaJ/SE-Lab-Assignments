%macro rw 3
  mov rax, %1
  mov rdi, 01
  mov rsi, %2
  mov rdx, %3 
  syscall
%endmacro rw

section .data
count db 03
arr dq 1645487569236547h, 9548123459878521h, 1246561231235874h
largest dq 0
msg1 db "The largest number is = "

section .bss
resultarr  resb 16
res resb 1

section .text
global _start
_start:
             

mov rbp, arr

up: 
   mov rax, [rbp]
   cmp rax, qword[largest]
   jns next
   mov qword[largest], rax
  
next:
   add rbp, 08
   dec byte[count]
jnz up
xy:

rw 01, msg1, 28
call hta
                        
mov rax,60
mov rdi,00
syscall

hta:
   mov rdi, resultarr
   mov byte[count], 16
   mov rax, qword[largest]
down: 
   rol rax, 04
   mov bl, al
   and bl, 0Fh
   cmp bl, 09h
   jle neg
   add bl, 07h
neg: 
   add bl, 30h
   mov [rdi], bl
   inc rdi
   dec byte[count]
jnz down
   
rw 01, resultarr, 16
ret
