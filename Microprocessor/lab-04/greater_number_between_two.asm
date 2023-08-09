.MODEL SMALL
.STACK 100h
.DATA

    MSGA DB "Input first number: ","$"
    MSGB DB 13,10,"Input second number:","$"
    MSGC DB 13,10,"The greater number is: ","$"
    
    NUM1 db ?
    NUM2 db ?
    NUM3 db ?

.CODE

MAIN PROC NEAR

    MOV AX, @DATA
    MOV DS, AX 
    
    LEA DX,MSGA
    MOV AH,9
    INT 21H
    
    MOV AH,1
    INT 21H
    MOV BL,AL
    
    LEA DX,MSGB
    MOV AH,9
    INT 21H
    
    MOV AH,1
    INT 21H
    MOV CL,AL
    
    SUB BL,48
    SUB CL,48
    
    CMP BL,CL
    JG NEXT
    
    
    
    LEA DX,MSGC
    MOV AH,9
    INT 21H
    MOV AH,2
    ADD CL,48
    MOV DL,CL
    INT 21H
    JMP EXIT
    
    NEXT:
    LEA DX,MSGC
    MOV AH,9
    INT 21H
    MOV AH,2
    ADD BL,48
    MOV DL,BL
    INT 21H   
    
    
    
EXIT:   
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN
    
