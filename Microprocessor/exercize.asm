.MODEL SMALL
.STACK 100H

.CODE
MAIN PROC
   
    
    
    MOV AH,1
    INT 21H
    MOV CL,AL
    
   
    
    INT 21H
    MOV BL,AL
    
             
             
    SUB CL,BL
    ADD CL,48
    
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    MOV AH,2
    MOV DL,CL
    INT 21H
    
    
    
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN



