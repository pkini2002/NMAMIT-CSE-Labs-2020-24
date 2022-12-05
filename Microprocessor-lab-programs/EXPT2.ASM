;Write ALP macros: 
;To read a character from the keyboard in the module (1) (different file).
;To display a character in module (2) (different file).
;Use the above two modules to read a string of characters from the keyboard 
;terminated by the carriage return and print the string on the display in the next line.





INCLUDE F1.TXT
INCLUDE F2.TXT

DATA SEGMENT
msg1 db 10,13, "Enter string:$"
msg2 db 10,13, "Entered string is:$"
str db 50 DUP(?)
n db ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:MOV AX,DATA
      MOV DS,AX
      LEA DX,msg1
      MOV AH,09H
      INT 21H
      LEA SI,str
      CALL READSTRING
      MOV n,CL
      LEA DX,msg2
      MOV AH,09H
      INT 21H
      LEA SI,str
      MOV CL,n
      CALL DISPSTRING
      MOV AH,4CH
      INT 21H

READSTRING PROC NEAR
      MOV CL,00H
UP:   CMP CL,50
      JZ L1
      READCHAR
      CMP AL,0DH
      JZ L1
      MOV [SI],AL
      INC SI
      INC CL
      JMP UP
L1:   RET
READSTRING ENDP

DISPSTRING PROC NEAR
UP2:CMP CL,00
    JZ L2
    MOV DL,[SI]
    DISPCHAR
    INC SI
    DEC CL
    JMP UP2
L2: RET
DISPSTRING ENDP
CODE ENDS
END START

