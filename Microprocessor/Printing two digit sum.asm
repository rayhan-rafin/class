.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC 
    MOV AH,1
    INT 21H
    MOV BL,AL
    
    INT 21H
    MOV CL,AL
    
    
    ADD AL,BL
    MOV AH,0
    AAA 
    
    MOV BX,AX 
    ADD BH,48
    ADD BL,48
    
    
    
    MOV AH,2
    MOV DL,BH
    INT 21H
    MOV DL,BL
    INT 21H
    
   
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN
    
    