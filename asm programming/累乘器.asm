DATAS SEGMENT
	STRING1 DB 0DH,0AH,"ERROR$"
    NUM DW 0
    RESULTH DW 0
    RESULTL DW 0
    COUNT DW 0
    ;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
INPUT:   

    MOV AH,01H;����
    INT 21H
    
    CMP AL,13;ENTER�������һ��
    JZ STEP2
    
    CMP AL,'0';�жϺϷ���
    JB ERR1
    CMP AL,'9'
    JA ERR1
    
    SUB AL,'0'    
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
;
;
;
	MOV DL,'A'
	MOV AH,2
	INT 21H
	
	MOV AX,1
	PUSH AX
	MOV AX,NUM;��ax��ֵ 
	CALL MULDW;�����ӳ���
;
;	
;
	MOV DL,'B'
	MOV AH,2
	INT 21H
	
STEP3:  ;ת��Ϊʮ���Ʒ����ջ��
	
	MOV CX,10;��ų���
	MOV DX,RESULTH
	MOV AX,RESULTL
	PUSH AX;�����16λ
	MOV AX,DX;��16λ����ax
	MOV DX,0;DIV��dx ax���ӵ�˫�ֳ���Դ�����������Դ˴�dx����	
	DIV CX;�̷���ax ��������dx	
	MOV BX,AX;�̷���bx
	POP AX;�ó���16λ
	DIV CX;�̷���ax ��������dx
	MOV CX,DX;��������cx
	MOV DX,BX;��16λ����dx ��16λ����ax
	
	MOV RESULTH,DX
	MOV RESULTL,AX
	PUSH CX;��������ջ
	
	MOV CX,COUNT;������һ
	INC CX;
	MOV COUNT,CX;
	
	CMP DX,0;��16λ��Ϊ0 ���̿϶���Ϊ0 �����̳�
	JNZ STEP3		 
	CMP AX,0;��16λΪ0 ��16λ��Ϊ0 �����̳�
	JNZ STEP3
	
	MOV CX,COUNT;��Ϊ0 �趨���ѭ������
	
OUTPUT:
    
    POP DX;�������stack�ε�һ�����ó� ����dx
    ADD DX,'0';����ֵת��Ϊ�ַ�����dx
    
    MOV AH,2
    INT 21H;���dl��ASCII��Ӧ���ַ�
    
    LOOP OUTPUT;CX�ݼ���0ʱֹͣ	
    
    MOV AH,4CH
    INT 21H	

	
MULDW PROC NEAR ;�ӳ��� ���۳˽���������ݶ�
;
;
;	
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX	
	
	MOV DL,'C'
	MOV AH,2
	INT 21H
	
	POP DX
	POP CX
	POP BX
	POP AX
;
;
;	
	CMP AX,0;NUM�Ƿ�Ϊ0
	JNZ STEP4
	MOV RESULTL,1
	JMP RETURN

STEP4:
	
	PUSH AX
	DEC AX
	CALL MULDW
	
RETURN:
	
	POP AX	
	MUL RESULTL;N*[(N-1)!��16λ] ����ĵ�16λ����ax ��16λ����dx
	MOV BX,DX;BX��ʱ��Ÿ�16λ
	MOV RESULTL,AX;��16λ�������ݶ�
	MUL RESULTH;N*[(N-1)!��16λ] ���Ӧ��ֻ���ڵ�16λ ����ax
	ADD AX,BX;ʵ��˫�ֳ˷� �����ĸ�16λ����ax
	MOV RESULTH,AX;��16λ�������ݶ�

	RET
MULDW ENDP

	    
ERR1:

	LEA DX,STRING1
	MOV AH,9
	INT 21H
	
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START













