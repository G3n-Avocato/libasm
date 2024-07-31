# libasm
Doc for lib asm x86_64  
Intel Syntax :   <_instruction_> <_dest_>, <_src_>

## Doc ASM x86_64 linux
* Section
    * section .data -> declare initialized data or constants
    * section .bss -> declare variables
    * section .text -> keep the actual code, start with "global <_name_start_>

* General Registers
    * rax - n* syscall - input/output for return fct
    * rdi - 1e arg
    * rsi - 2e arg
    * rdx - 3e
    * r10 - 4e
    * r8 - 5e
    * r9 - 6e
    * rcx - Loop counters
    * rbx - base

* Segment Registers
    * CS - Code segment - code segment for next instruction
    * DS - Data segment - addr segment data for program
    * ES - Extra segment - addr the segment of our choice
    * SS - Stack segment

* Offset Registers
    * IP - Instruction pointer next instruction (CS:IP)
    * SP - Stack pointer ()
    * BP - Base pointer

* Control Registers (F -- Flag -- Bit number)
    * OF -- Overflow -- 11
    * DF -- Direction -- 10
    * IF -- Interupt -- 9
    * TF -- Trap -- 8
    * SF -- Sign -- 7
    * ZF -- Zero -- 6
    * AF -- Auxiliary Carry -- 4
    * PF -- Parity -- 2
    * CF -- Carry -- 1

## Instructions

* CALL - 
* MOV <_dest_>, <_src_> - copy src content to dest 
* XCHG <_dest_>, <_src_> - "exchange" echange contenue de src avec dest

* JMP <_label_> - jump to the instruction pointed by label
* CMP <_dest_>, <_src_> - compare instruction

* CMP JMP Instructions :
    * JE - "Jump if Equal" - jump to label if ZF = 1 (Zero-flag == 1 if res from previous operations is 0)
    * JE == JZ - "Jump if zero"
    * JNE == JNZ -  
    * signee
    * JG - "Jump if Greater"
    * JGE - "Jump if Greater or Equal"
    * JL - "Jump if Less"
    * JLE - "Jump if Less or Equal
    * non signee
    * JA - "Jump if Above"
    * JAE - "Jump if Above or Equal"
    * JB - "Jump if Below"
    * JBE - "Jump if Below or Equal
    * JMP FOR FLAGS
    * JC - "Jump if Carry" - if CF = 1 - use for check error from call 
    * JNC - if CF = 0
    * JO - "Jump if Overflow" - OF = 1
    * JNO - "Jump if not Overflow" - OF = 0

* INC <_dest_> - incremente dest
* ADD <_dest_>, <_src_> - add src to dest
* DEC <_dest_> - decrement dest
* SUB <_dest_>, <_src_> - sub src to dest
* XOR <_dest_>, <_src_> - Logical OR bit to bit - reset a register

* PUSH <_src_> - stack src - sp is decremented by 2
* POP <_dest_> - 

## Dictionary

Bit - unit system binaire (0 false | 1 true)
Octet - 8 bit sequence
Word - 2 octet = 16 bits
Double Word - 4 octet = 32 bits

## Sources

Syscall asm x86_64
* https://syscalls.w3challs.com/?arch=x86_64

Instructions asm x86_64
* https://www.gladir.com/CODER/ASM8086/x86-64.htm

Tuto asm x86_32 start
* https://www.tutorialspoint.com/assembly_programming/assembly_registers.htm

Debug asm
* https://github.com/hugsy/gef?tab=readme-ov-file

<< CMD GEF GDB >>
gdb <_name_exec_>
break <_name_fct_>
run r
si (stepi)
ni (nexti)
c (resumes execution until the next break)
quit