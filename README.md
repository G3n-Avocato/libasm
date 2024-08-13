# libasm
**Intel Syntax :   <_instruction_> <_dest_>, <_src_>**

## Doc ASM x86_64 linux
* Section
    * **section .data** -- declare initialized data or constants
    * **section .bss** -- declare variables
    * **section .text** -- keep the actual code, start with "global <_name_start_>

* General Registers
    * **RAX** -- n* syscall -- input/output for return fct
    * **RDI** -- 1e arg
    * **RSI** -- 2e arg
    * **RDX** -- 3e
    * **R10** -- 4e
    * **R8** -- 5e
    * **R9** -- 6e
    * **RCX** -- Loop counters
    * **RBX** -- base

* Segment Registers
    * **CS** -- Code segment -- code segment for next instruction
    * **DS** -- Data segment -- addr segment data for program
    * **ES** -- Extra segment -- addr the segment of our choice
    * **SS** -- Stack segment

* Offset Registers
    * **IP** -- Instruction pointer next instruction (CS:IP)
    * **SP** -- Stack pointer
    * **BP** -- Base pointer

* Control Registers _(F -- Flag -- Bit number)_
    * **OF** -- Overflow -- 11
    * **DF** -- Direction -- 10
    * **IF** -- Interupt -- 9
    * **TF** -- Trap -- 8
    * **SF** -- Sign -- 7
    * **ZF** -- Zero -- 6
    * **AF** -- Auxiliary Carry -- 4
    * **PF** -- Parity -- 2
    * **CF** -- Carry -- 1

## Instructions

* **CALL <_label_>** -- 
* **MOV <_dest_>, <_src_>** -- copy src content to dest 
* **XCHG <_dest_>, <_src_>** -- "exchange" src content with dest

* **JMP <_label_>** -- jump to the instruction pointed by label
* **CMP <_dest_>, <_src_>** -- compare instruction

* CMP JMP Instructions :
    * * equal
    * **JE** -- "Jump if Equal" - jump to label if ZF = 1 (Zero-flag == 1 if res from previous operations is 0)
    * **JE == JZ** -- "Jump if zero"
    * **JNE == JNZ** -- "Jump if Not Zero/Equal"  
  
    * * signed
    * **JG** -- "Jump if Greater"
    * **JGE** -- "Jump if Greater or Equal"
    * **JL** -- "Jump if Less"
    * **JLE** -- "Jump if Less or Equal  
  
    * * unsigned
    * **JA** -- "Jump if Above"
    * **JAE** -- "Jump if Above or Equal"
    * **JB** -- "Jump if Below"
    * **JBE** -- "Jump if Below or Equal  
      
    * * JMP FOR FLAGS
    * **JC** -- "Jump if Carry" -- if CF = 1 -- use for check error from call 
    * **JNC** -- if CF = 0
    * **JO** -- "Jump if Overflow" -- OF = 1
    * **JNO** -- "Jump if not Overflow" -- OF = 0

* **INC <_dest_>** -- incremente dest
* **ADD <_dest_>, <_src_>** -- add src to dest
* **DEC <_dest_>** -- decrement dest
* **SUB <_dest_>, <_src_>** -- sub src to dest
* **XOR <_dest_>, <_src_>** -- Logical OR bit to bit -- reset a register

* **PUSH <_src_>** -- stack src -- sp is decremented by 2
* **POP <_dest_>** - 

* **TEST <_dest>, <_src_>** -- effectue "ET binaire" sans modif valeur mais met a jour les flags ZF/SF/PF -- use for check null res

## Callee's Rules

- allocate local variables _by using registers_ or _making space on the stack_
> sub rsp, 12
> add rsp, 12
- return value in RAX - return to the caller by exec a _ret_ instruction

- hold-over from the 32 bits calling convention
> push rbp
> mov rbp, rsp
> ...
> pop rbp


## Dictionary

Bit -- binary system unit  (0 false | 1 true)  
Octet -- 8 bit sequence  
Word -- 2 octet = 16 bit 
Double Word -- 4 octet = 32 bit 

## Sources

- Syscall asm x86_64  
[syscall](https://syscalls.w3challs.com/?arch=x86_64)

- Instructions asm x86_64  
[gladir instruction](https://www.gladir.com/CODER/ASM8086/x86-64.htm)

- Tuto asm x86_32 start  
[intro](https://www.tutorialspoint.com/assembly_programming/assembly_registers.htm)

- Debug asm  
[gef debug asm](https://github.com/hugsy/gef?tab=readme-ov-file)

CMD GEF GDB =>  
> gdb <_name_exec_>  
> break <_name_fct_>  
> run r  
> si (stepi)  
> ni (nexti)  
> c (resumes execution until the next break)  
> quit  
> context regs

- Calling Convention Src
[Calling convention x86_64](https://aaronbloomfield.github.io/pdr/book/x86-64bit-ccc-chapter.pdf)