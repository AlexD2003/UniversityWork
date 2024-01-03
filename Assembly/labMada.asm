bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s db 2,4,6,8
    ls equ $-s
    
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
            mov bl, 4
            idiv bl
            cmp ah, 0
            je adauga
            jne next
            
            adauga:
                mov al, byte[s+esi]
                mov byte[d+edi], al
                inc esi
                inc edi
            jmp myendif
            
            next:
                inc esi
                
            myendif:
        
        loop repeta
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
