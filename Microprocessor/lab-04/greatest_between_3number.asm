.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
    MOV AH,1
    INT 21H
    MOV BL,AL
    
    INT 21H
    MOV BH,AL
    
    INT 21H
    MOV CL,AL

;BL GREATER    
    CMP BL,BH 
    JGE L1
    
;BH GREATER    
    CMP BH,CL
    JGE L2
    
;PRINT CL
    MOV DL,CL
    MOV AH,2
    INT 21H
    JMP EXIT 

    L1:
;BL GREATER 
    CMP BL,CL
    JGE L3
    
    MOV DL,CL
    MOV AH,2
    INT 21H
    JMP EXIT
    
;PRINT BH    
    L2:
    MOV DL,BH
    MOV AH,2
    INT 21H
    JMP EXIT 
    
;PRINT BL     
   L3:
    MOV DL,BL
    MOV AH,2
    INT 21H 
    
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN
