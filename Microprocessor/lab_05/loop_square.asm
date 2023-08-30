.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
   MOV CX,5
   MOV BH,5
  
   
  TOP:
    MOV AH,2
    MOV DL,'*'
    INT 21H
    DEC BH
    
    CMP BH,0
    JE NEXT
    
    JMP TOP
    
   NEXT:
   MOV AH,2
   MOV DL,10
   INT 21H
   MOV DL,13
   INT 21H
   
   
   MOV BH,5
   CMP BH,0
   JE EXIT
   
   LOOP TOP 
    
    
   
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN
