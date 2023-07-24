;Multiplication of two one digit number in assembly 
 ;language
 
 
.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
    
    MOV AH,1
    INT 21H
    MOV BH,AL
    SUB BH,48
    
   
    
    
    MOV AH,1
    INT 21H
    MOV BL,AL
    SUB BL,48
    
    
    MOV CL,BH
    MOV CH,00
    MOV AX,CX  
    
    DIV BL
    AAD  
 
    ADD AL,48
    
    
    MOV AH,2
    MOV DL,AL
    INT 21H
    
    
    
    
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN
 
            ;THANK YOU GUYS