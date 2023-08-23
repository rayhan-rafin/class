.MODEL SMALL
.STACK 100h
.DATA

    
    
    MSGA DB 13,10,"Input First number:","$"
    MSGB DB 13,10,"Input Second number:","$"
    MSGC DB 13,10,"Input Third number:","$"
    
    MSGF DB 13,10,"FIRST NUMBER:","$"
    MSGS DB 13,10,"SECOND NUMBER:","$"
    MSGT DB 13,10,"THIRD NUMBER:","$"
    
    GREATEST DB 13,10,"LARGEST NUMBER:","$"
    MIDDLE DB 13,10,"MIDDLE NUMBER:","$"
    SMALLEST DB 13,10,"SMALLEST NUMBER:","$"
    
    INPUT DB 13,10,"INPUT A CHARACTER:","$"
    OUTPUT1 DB 13,10,"YOUR ENTERED CHAR IS VOWEL","$"
    OUTPUT2 DB 13,10,"YOUR ENTERED CHAR IS CONSONENT","$"
    
    
    NUM1 DB 0
    NUM2 DB 0
    NUM3 DB 0

.CODE
MAIN PROC NEAR

    MOV AX, @DATA
    MOV DS, AX
    
    
                     ;READ 3 NUMBERS  (A) 
    
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
    
    
    
   ;                  DISPLAY NUMBERS(A)
    ;PRINT MSGF
    LEA DX, MSGF
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,NUM1
    INT 21H
    
     ;PRINT MSGS
    LEA DX, MSGS
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,NUM2
    INT 21H
    
     ;PRINT MST
    LEA DX, MSGT
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,NUM3
    INT 21H    
    
    ;                 LARGEST,MID,SMALL(A)
    
    ;BL=NUM1,BH=NUM2,CL=NUM3
    MOV BL,NUM1
    MOV BH,NUM2
    MOV CL,NUM3
    
    CMP BL,BH
    JGE L5
    
    CMP BH,CL
    JGE L7
    
    JMP L8
    
    
    L5:
    CMP BL,CL
    JGE L6
     
     
    ;                      BL GREATEST
    L6:
    CMP BH,CL
    JGE L9
    
    ;BL>CL>BH
    
    ;PRINT GREATEST
    LEA DX, GREATEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BL
    INT 21H
    
    ;PRINT MIDDLE
    LEA DX, MIDDLE
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,CL
    INT 21H
    
    ;PRINT SMALLEST
    LEA DX, SMALLEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BH
    INT 21H
    JMP NEWL
     
    
    ;BL>BH>CL
    L9:
    
    ;PRINT GREATEST
    LEA DX, GREATEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BL
    INT 21H
    
    ;PRINT MIDDLE
    LEA DX, MIDDLE
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BH
    INT 21H
    
    ;PRINT SMALLEST
    LEA DX, SMALLEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,CL
    INT 21H
    JMP NEWL
    
    ;                   BH GREATEST
    L7:
    CMP BL,CL
    JGE L10
    
    ;BH>CL>BL
    
    ;PRINT GREATEST
    LEA DX, GREATEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BH
    INT 21H
    
    ;PRINT MIDDLE
    LEA DX, MIDDLE
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,CL
    INT 21H
    
    ;PRINT SMALLEST
    LEA DX, SMALLEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BL
    INT 21H
    JMP NEWL 
    
    ;BH>BL>CL
    L10:
    
    ;PRINT GREATEST
    LEA DX, GREATEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BH
    INT 21H
    
    ;PRINT MIDDLE
    LEA DX, MIDDLE
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BL
    INT 21H
    
    ;PRINT SMALLEST
    LEA DX, SMALLEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,CL
    INT 21H
    JMP NEWL
    
    ;                   CL GREATEST
    L8:
    CMP BL,BH
    JGE L11
    
    ;CL>BH>BL
    
    ;PRINT GREATEST
    LEA DX, GREATEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,CL
    INT 21H
    
    ;PRINT MIDDLE
    LEA DX, MIDDLE
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BH
    INT 21H
    
    ;PRINT SMALLEST
    LEA DX, SMALLEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BL
    INT 21H
    JMP NEWL 
    
    ;CL>BL>BH
    L11:
    
    ;PRINT GREATEST
    LEA DX, GREATEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,CL
    INT 21H
    
    ;PRINT MIDDLE
    LEA DX, MIDDLE
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BL
    INT 21H
    
    ;PRINT SMALLEST
    LEA DX, SMALLEST
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,BH
    INT 21H
     
NEWL:
    LEA DX, INPUT
    MOV AH,9
    INT 21H
                    
    ;INP NUM1
    MOV AH,1
    INT 21H 
    MOV BL,AL
    
    CMP BL,97
    JE VOWEL
    
    CMP BL,101
    JE VOWEL
    
    CMP BL,105
    JE VOWEL
    
    CMP BL,111
    JE VOWEL
    
    CMP BL,117
    JE VOWEL
    
    CMP BL,65
    JE VOWEL
    
    CMP BL,69
    JE VOWEL
    
    CMP BL,73
    JE VOWEL
    
    CMP BL,79
    JE VOWEL
    
    CMP BL,85
    JE VOWEL
    
    CONSONENT:
    LEA DX, OUTPUT2
    MOV AH,9
    INT 21H
    JMP EXIT
    
    VOWEL:
    LEA DX, OUTPUT1
    MOV AH,9
    INT 21H
    
   
    
EXIT:   
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN           
