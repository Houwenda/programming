DATAS SEGMENT
    string1 db 'INPUT A STRING:',0dH,0aH
    string2 db 'YOUR STRING IS:'
    string3 db ?;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV BX,0
;���   
    MOV CX,17
A:  MOV DL,string1[bx]
    MOV AH,2
    INT 21H
    INC BX
    LOOP A
    
;����
	MOV BX,0    
B:  MOV AH,1
	INT 21H
	CMP AL,13
	JZ NEXT
	MOV string3[BX],AL
	INC BX
	JMP B
;���
NEXT:
	MOV CX,0FH
	MOV SI,0
A2:	MOV DL,string2[SI]
	MOV AH,2
	INT 21H
	INC SI
	LOOP A2
	
	MOV CX,BX
	MOV BX,0
E:	MOV DL,string3[BX]
	MOV AH,2
	INT 21H
	INC BX
	LOOP E
	    ;�˴��������δ���
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
