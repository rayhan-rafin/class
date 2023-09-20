.MODEL SMALL
.STACK 100H
.DATA
STAR DB ?
BLANK DB ? 

.CODE 
MAIN PROC 
                ; First code
    MOV CX,5
    MOV BX,1
    
   L1:
    PUSH CX
    MOV CX,BX 
    
   L3:
    MOV AH,2
    MOV DL,'*'
    INT 21H
    LOOP L3
    
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
    
    INC BX
    
    POP CX
    LOOP L1
    
    
    MOV CX,4
    MOV BH,4
    MOV BL,2
    
    MOV STAR,BH
    MOV BLANK,BL
    
   L4:
    CMP BLANK,0
    JE L5
    DEC BLANK
    ;CMP BLANK,0
    JMP L4
    
   L5:
    MOV AH,2
    MOV DL,'*'
    INT 21H
    DEC STAR
    CMP STAR,0
    JNE L5 
    
  L6:  
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
    
    DEC BH
    MOV STAR,BH
    
    INC BL
    MOV BLANK,BL
    
    LOOP L4 
    
    
                    ;SECOND CODE  
                    
                                   
                    
   MOV AH,1
   INT 21H
   MOV BL,AL
   
   ;NEWLINE
   MOV AH,2
   MOV DL,10
   INT 21H
   MOV DL,13
   INT 21H
   
   
   MOV CL,'1'
  L:  
   MOV AH,2
   MOV DL,CL
   INT 21H
   
   ;NEWLINE
   MOV AH,2
   MOV DL,10
   INT 21H
   MOV DL,13
   INT 21H
   
   INC CL
   INC CL
   CMP BL,CL
   JL EXIT
   JMP L
    
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN
    