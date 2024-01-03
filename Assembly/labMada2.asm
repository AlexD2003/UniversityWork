bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s dw 1709h, 0082h, 0E20h
    ls equ ($-s)/2
    d resb ls
    

; our code starts here
segment code use32 class=code
    start:
        mov esi, 0
        mov edi, 0
        mov ecx, ls
        
        repeta:
            mov al, byte[s+esi]
            movsx ax, al
            mov bl, 9
            idiv bl
            cmp ah, 0
            je adauga
            jne next
            
            adauga:
                mov al, byte[s+esi]
                mov byte[d+edi], al
                add esi, 2
                add edi, 2
                
            jmp my_endif
            
            next:
                add esi, 2
          
    
            my_endif:
            
        loop repeta
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
