;Write an ALP to read your name from the keyboard and display it at a specified location on the screen in front of the message “What is your name?” You must 
;clear the entire screen before display.

CLRSCR MACRO
  MOV AH,00H
  MOV AL,02H
  INT 10H
ENDM

SETCURSOR MACRO ROW,COL
   MOV DL,COL
   MOV DH,ROW
   MOV BH,00H
   MOV AH,02H
   INT 10H
ENDM

DATA SEGMENT
MSG1 DB 10,13,"ENTER YOUR NAME:$"
MSG2 DB 10,13,"WHAT IS YOUR NAME?$"
STR DB 30 DUP(?)
N DB ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:MOV AX,DATA
      MOV DS,AX
      LEA DX,MSG1
      MOV AH,09H
      INT 21H
      LEA SI,STR
      CALL READSTRING
      MOV N,CL
      CLRSCR
      SETCURSOR 10,30
      LEA DX,MSG2
      MOV AH,09H
      INT 21H
      LEA SI,STR
      MOV CL,N
      CALL DISPSTRING
      MOV AH,01H
      INT 21H
      MOV AH,4CH
      INT 21H

READSTRING PROC NEAR
     MOV CL,00H
UP:  MOV AH,01H
     INT 21H
     CMP AL,0DH
     JZ L1
     MOV [SI],AL
     INC SI
     INC CL
     JMP UP
L1:  RET
READSTRING ENDP

DISPSTRING PROC NEAR
UP1:CMP CL,00H
    JZ L2
    MOV DL,[SI]
    MOV AH,02H
    INT 21H
    INC SI
    DEC CL
    JMP UP1
L2: RET
DISPSTRING ENDP
CODE ENDS
END START


