.MODEL SMALL
.STACK 100h
.DATA

    FAM DB "RAYHAN RAFIN$"
    
    MSGA DB 13,10,"Input First number:","$"
    MSGB DB 13,10,"Input Second number:","$"
    MSGC DB 13,10,"Input Third number:","$"
    
    MID DB 13,10,"MIDDLE NUMBER IS:","$"
    
    SUM1 DB 13,10,"THE SUM OF ","$"
    SUM2 DB " AND $"
    SUM3 DB " IS : $"
    
    NUM1 DB 0
    NUM2 DB 0
    NUM3 DB 0

.CODE
MAIN PROC NEAR

    MOV AX, @DATA
    MOV DS, AX
    
                    ;PRINT FAMILY NAME (A)
    
    LEA DX, FAM
    MOV AH,9
    INT 21H
    
    ;NEWLINE
 
    MOV AH,2
    MOV DL,10
    INT 21H
    
    MOV AH,2
    MOV DL,13
    INT 21H  
    
    
                     ;READ 3 NUMBERS  (B) 
    
    ;PRINT MSGA
    LEA DX, MSGA
    MOV AH,9
    INT 21H
                    
    ;INP NUM1
    MOV AH,1
    INT 21H 
    MOV NUM1,AL
    
    ;PRINT MSGB
    LEA DX, MSGB
    MOV AH,9
    INT 21H
    
    ;INP NUM2
    MOV AH,1
    INT 21H 
    MOV NUM2,AL
    
    ;PRINT MSGC
    LEA DX, MSGC
    MOV AH,9
    INT 21H
    
    
    ;INP NUM3
    MOV AH,1
    INT 21H 
    MOV NUM3,AL
    
    ;NEWLINE
 
    MOV AH,2
    MOV DL,10
    INT 21H
    
    MOV AH,2
    MOV DL,13
    INT 21H     
    
    
                        ;DISPLAY MIDDLE (C) 
                        
                        
    ;BL=NUM1,BH=NUM2,CL=NUM3
    MOV BL,NUM1
    MOV BH,NUM2
    MOV CL,NUM3
    
    ; COMPARE EACH REGISTER AS THEY ARE MID                    
    CMP BL,BH
    JLE L1
    
    
    
    CMP BH,CL
    JGE L3
    
    L1:
    CMP BL,CL
    JGE L2
    JMP L4
    
    
    L2:
    
    ;PRINT MID MSG
    LEA DX, MID
    MOV AH,9
    INT 21H                  
    
    ;PRINT BL
    MOV AH,2
    MOV DL,BL
    INT 21H
    JMP NEWL
    
    L3:
    
    ;PRINT MID MSG
    LEA DX, MID
    MOV AH,9
    INT 21H                  
    
    ;PRINT BH
    MOV AH,2
    MOV DL,BH
    INT 21H
    JMP NEWL
    
    L4:
    ;PRINT MID MSG
    LEA DX, MID
    MOV AH,9
    INT 21H                  
    
    ;PRINT CL
    MOV AH,2
    MOV DL,CL
    INT 21H
                    ;SUM OF LOWEST TWO(D)
    
    NEWL:
                                        
    ;BL=NUM1,BH=NUM2,CL=NUM3
    CMP BL,BH
    JGE L5
    
    CMP BH,CL
    JGE L7
    
    JMP L8
    
    
    L5:
    CMP BL,CL
    JGE L6
     
     
    ;BL GREATEST
    L6:
    
    ;PRINT SUM1
    LEA DX, SUM1
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BH
    INT 21H
   
    ;PRINT SUM2 
    LEA DX, SUM2
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,CL
    INT 21H
    
    ;PRINT SUM3 
    LEA DX, SUM3
    MOV AH,9
    INT 21H
    
    ;SUM OF NUM2,NUM3 IN DL
    ADD BH,CL
    SUB BH,48
    MOV DL,BH
    
    MOV AH,2
    INT 21H
    JMP EXIT
     
    ;BH GREATEST
    L7:
    
    ;PRINT SUM1
    LEA DX, SUM1
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BL
    INT 21H
   
    ;PRINT SUM2 
    LEA DX, SUM2
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,CL
    INT 21H
    
    ;PRINT SUM3 
    LEA DX, SUM3
    MOV AH,9
    INT 21H
    
    ;SUM OF NUM1,NUM3 IN DL
    ADD BL,CL
    SUB BL,48
    MOV DL,BL
    
    MOV AH,2
    INT 21H
    JMP EXIT
    
    ;CL GREATEST
    
    L8:
    ;PRINT SUM1
    LEA DX, SUM1
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BL
    INT 21H
   
    ;PRINT SUM2 
    LEA DX, SUM2
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BH
    INT 21H
    
    ;PRINT SUM3 
    LEA DX, SUM3
    MOV AH,9
    INT 21H
    
    ;SUM OF NUM1,NUM2 IN DL
    ADD BL,BH
    SUB BL,48
    MOV DL,BL
    
    MOV AH,2
    INT 21H
    JMP EXIT
    
EXIT:   
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN           
