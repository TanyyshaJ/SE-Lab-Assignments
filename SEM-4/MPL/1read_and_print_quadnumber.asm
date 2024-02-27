%macro rw 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro rw

section .data
count db 05h
msg1 db "Enter quad word no.: "
msg2 db "The quad word no. is: "

section .bss
numarr resb 17

global _start
section .text
_start:


next:
rw 01,msg1,16

rw 00,numarr,17

rw 01,msg2,19

rw 01,numarr,17

dec byte[count]
jnz next

mov rax,60
mov rdi,00
syscall
