DATAS SEGMENT
	STRING1 DB 'ERROR',0dh,0ah,'$'
	STRING2 DB 'NUM=$'
	STRING3 DB 'SUM=$'
	STRING4 DB 'OVERFLOW$'
    NUM DW 0
    SUM DW 0;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    LEA DX,STRING2
	MOV AH,9
	INT 21H
    
INPUT:  
 
    MOV AH,01H;����
    INT 21H
   
    CMP AL,13;�жϻس�
    JZ STEP2
    
    CMP AL,'0';�жϺϷ�����
    JB ERR1
    CMP AL,'9'
    JA ERR1
    SUB AL,'0';�ַ�ת��Ϊ����
    MOV AH,0;
    PUSH AX;��ʱ�ճ�AX
    
    MOV AX,NUM
    
    MOV BX,10;��������bx
    MUL BX;��num��BX(10)����AX
    POP DX;����������ַ���DX
    ADD DX,AX;ʵ�������λ��
    MOV NUM,DX;�ѵõ��Ķ�λ������data��
    
    JMP INPUT
    
STEP2:
	
	MOV AX,SUM;0
	MOV DX,NUM

ADDUP:
	
	ADD AX,DX;�ۼ�
	JO ERR2
	DEC DX;NUM��1
	CMP DX,0
	JNZ ADDUP;������ֵһֱ�ӵ�0
    
	MOV SUM,AX;���ۼӵõ������Ż�data��
	MOV CX,0;��cx������λ����Ĵ��������Դ˴���cx����
	MOV BX,10;Ϊdiv�趨����
	
STEP3:	

	MOV DX,0;div��dx ax���ӳɵ�˫�����ݳ���bx,���Դ˴���dx����
	DIV BX;������ax ��������dx	        
    PUSH DX;��������stack��
    INC CX;������õĴ�����һ
    CMP AX,0;
    JNZ STEP3;�̲�Ϊ0ʱ�����̳�   
    
	LEA DX,STRING3
	MOV AH,9
	INT 21H

OUTPUT:
    
    POP DX;�������stack�ε�һ�����ó� ����dx
    ADD DX,'0';����ֵת��Ϊ�ַ�����dx
    
    MOV AH,2
    INT 21H;���dl��ASCII��Ӧ���ַ�
    
    LOOP OUTPUT;CX�ݼ���0ʱֹͣ
    
    MOV AH,4CH
    INT 21H  
    
ERR1:
	LEA DX,STRING1
	MOV AH,9
	INT 21H
    ;�˴��������δ���
    MOV AH,4CH
    INT 21H
    
ERR2:
	LEA DX,STRING4
	MOV AH,9
	INT 21H
    MOV AH,4CH
    INT 21H
        
CODES ENDS
    END START



