DATAS SEGMENT
    A DW  65520

    COUNT DW 0 
    
DATAS ENDS

STACKS SEGMENT
    DB 100 DUP
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
   
    MOV AX,A    
    MOV CX,10   
    CMP AX,0     
    JL L2              

    
L1: XOR DX,DX   
    IDIV CX       
    PUSH DX    
    
    INC COUNT
    CMP AX,0
    JNE L1
    JMP L5
    
L2: NEG AX     
L3: XOR DX,DX
      
    IDIV CX       
    PUSH DX    
    
    INC COUNT
    CMP AX,0
    JNE L3
    JMP L4


L4: MOV DL,'-'     
    MOV AH,2
    INT 21H   
L5:                
    POP DX
    ADD DX,30H
    
    DEC COUNT
    CMP COUNT,0
    MOV AH,2
    INT 21H
    JNE L5
   
    MOV AH,4CH
    INT 21H
    
CODES ENDS
    END START
