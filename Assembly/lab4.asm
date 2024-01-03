bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;if a >= (12-c) then e = c/7 else e = (a+3)*2 – c
    a db 10
    b dw 15
    c dw 20
    d db 25
    e dd 30
    f db 35

; our code starts here
segment code use32 class=code
    start:
        ; ...
        movsx ax , byte[a] ; a->ax
        mov bx,word[c] ;c->bx
        mov dx,12 ; 12->dx
        sub dx,bx ;dx=12-c
        cmp ax,dx ;compare a with 12-c
        JGE ramurathen
        JL ramuraelse
        ramurathen: ;ramura greater or equal
        mov ax,word[c] ;c->ax
        cwd ;sign extend
        mov cx,7 ;7->cx
        idiv cx ;c/7
        mov [e],eax ;e->eax
        jmp myendif
        ramuraelse:;ramura less
        movsx ax,byte[a] ; a->ax
        add ax,3 ;ax+=3
        imul ax,2 ;ax*=2
        sub ax,word[c] ;ax-=c
        mov [e],eax ;e->eax
        myendif: ;end
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
