/******************************* 

��ɶ����� x^2+2^(x+1)-x^-1+3 �Ľ���
sin cos tan cot log arctan�Ⱥ��� 

*******************************/

using namespace std;
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath> 
#include <algorithm>
#include <stack>
#define ms(a,b) memset(a,b,sizeof(a))



double sum=0; 
/*
void arithmetic(char * str,double x){
	int barrier=0,i;
	string tmp_str;
//	cout<<str<<endl;


}

//ƥ�������е����ݽ��еݹ�  δ��� 
void brackets(char * str,double x){
	

	for(barrier=0;barrier<strlen(str);barrier++){
		if(str[barrier]=='('){
			for(i=1;i<strlen(str)-barrier;i++){
				if(str[barrier+i]!=')') tmp_str +=  str[barrier+i];
				else break;
			}
		}
	}	 
}
*/

//�����ʽ��x�滻Ϊָ������n 
char* replace_x(char * str, char * formula, double n){
	char num[20];
	int i,count,m,j;
	double k;
	//��double��ת��Ϊ�ַ��� 
	i = 0;
	m = int(n);  //С����ǰ�Ĳ��� 
	while(m/10!=0){
		m /= 10;
		i++;
	} 
	count = i + 1;
	m = int(n);
	while(i>=0){
		num[i] = m%10 + '0';
		m /= 10;
		i--;
	}
	num[count] = '.';
	i = 0;
	k = n - int(n);  //С�����Ĳ��� 
	k = floor(k * 10000.00000f + 0.5) / 10000.00000f;  //����С�������λ 
	while(k-int(k)!=0){
		k *= 10;
		i++;
	}
	num[count+i+1] = '\0';
	m = int(k);
	while(i>0){
		num[count+i] = m%10 + '0';
		m /= 10;
		i--;
	}
//  cout<<num; 
	count = 0;
	i= 0;
	while(i<strlen(str)){
		if(str[i]!='X'){
			formula[count] = str[i];
//			cout<<formula[count]<<endl;
			count++;
			i++;
		}
		//����x
		else{
			//xǰΪ��������*
			if(i!=0&&str[i-1]>='0'&&str[i-1]<='9'){
				formula[count] = '*';
//				cout<<formula[count]<<endl;
				count++;
				j = 0;
				while(j<strlen(num)){
					formula[count] = num[j];
//					cout<<formula[count]<<endl;
					count++;
					j++;
				}
				i++;
			}
			//ֱ���滻x����formula 
			else{
				j = 0;
				while(j<strlen(num)){
					formula[count] = num[j];
//					cout<<formula[count]<<endl;
					count++;
					j++;
				}
				i++;
			}
			count--;//ֱ���滻���һ��λ 
		}	
	} 
	formula[count] = '\0';
/*
	for(i=0;i<strlen(str);i++){
		if(str[i]!='X'){
			formula[i] = str[i];
		}
		//����x 
		else{
			//xǰΪ��������* 
			if(str[i-1]>='0'&&str[i-1]<='9'){
				str[i] = '*';
				i++;
				for(j=0;j<strlen(num);j++){
					formula[i] = num[j];
					i++;
				}
				i--; 
			}
			//ֱ���滻x����formula 
			else{
				for(j=0;j<strlen(num);j++){
					formula[i] = num[j];
					i++;
				}
				i--;
			} 
		}
			
	}
*/	 
	return formula; 
} 




//�������Ϸ��� Y=X^2+2X+1
bool check(char * str){
	int count,i;
	//��һ���ַ�ֻ����x�����ֻ�(	
	if(str[0]=='X'||str[0]=='('||(str[0]>='0'&&str[0]<='9')){} 
	else return false;
	
	//�м��ַ� 
	for(i=1;i<strlen(str)-1;i++){
		if(str[i]=='X'){
			//ÿ��xǰֻ�������ֻ�+-��^��( 
			if(str[i-1]=='+'||str[i-1]=='-'||str[i-1]=='('||str[i-1]=='^'||(str[i-1]>='0'&&str[i-1]<='9')){}
			else{
				cout<<"before x"<<endl;
				return false;
			} 
			//ÿ��x��ֻ����^��+-*/��)
			if(str[i+1]=='^'||str[i+1]=='+'||str[i+1]=='-'||str[i+1]==')'||str[i+1]=='*'||str[i+1]=='/'){} 
			else{
				cout<<"after x"<<endl; 
				return false;
			} 
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
			//�������ǰֻ�������ֻ�x��) 
			if(str[i-1]=='X'||str[i-1]==')'||(str[i-1]>='0'&&str[i-1]<='9')){}
			else if(str[i]=='-'&&str[i-1]=='^'){}  //���� x^-2 
			else{
				cout<<"before sign"<<endl;
				return false;
			} 
			//������ź�ֻ�������ֻ�x��(
			if(str[i+1]=='X'||str[i+1]=='('||(str[i+1]>='0'&&str[i+1]<='9')){}
			else{
				cout<<"after sign"<<endl;
				return false;
			} 
		}
		else if(str[i]=='('){
			//ÿ��(ǰֻ����^��+-*/
			if(str[i-1]=='^'||str[i-1]=='+'||str[i-1]=='-'||str[i-1]=='*'||str[i-1]=='/'){}
			else{
				cout<<"before ("<<endl;
				return false;
			} 
			//ÿ��(��ֻ�������ֻ�x 
			if(str[i+1]=='X'||(str[i+1]>='0'&&str[i+1]<='9')){}
			else{
				cout<<"after ("<<endl;
				return false;
			}
		} 
		else if(str[i]==')'){
			//ÿ��)ǰֻ�������ֻ�x
			if(str[i-1]=='X'||(str[i-1]>='0'&&str[i-1]<='9')){}
			else{
				cout<<"before )"<<endl;
				return false;
			}
			//ÿ��)��ֻ����^��+-*/ 
			if(str[i+1]=='^'||str[i+1]=='+'||str[i+1]=='-'||str[i+1]=='*'||str[i+1]=='/'){}
			else{
				cout<<"after )"<<endl;
				return false;
			}
		}
		else if(str[i]=='^'){
			//ÿ��^ǰֻ����)�����ֻ�x
			if(str[i-1]==')'||str[i-1]=='X'||(str[i-1]>='0'&&str[i-1]<='9')){}
			else{
				cout<<"before ^"<<endl;
				return false;
			}
			//ÿ��^��ֻ����(�����ֻ�x��-
			if(str[i+1]=='('||str[i+1]=='X'||str[i+1]=='-'||(str[i+1]>='0'&&str[i+1]<='9')){}
			else{
				cout<<"after ^"<<endl;
				return false;
			}
		}
		else if(str[i]=='.'){
			//ÿ��.ǰ��ֻ�������� 
			if(str[i-1]>='0'&&str[i-1]<='9'&&str[i+1]>='0'&&str[i+1]<='9'){}
			else{
				cout<<"near ."<<endl;
				return false;
			}
		}
	}
	
	//��β�ַ�ֻ����)�����ֻ�x
	if(str[strlen(str)-1]==')'||str[strlen(str)-1]=='X'||(str[strlen(str)-1]>='0'&&str[strlen(str)-1]<='9')){}
	else return false;
	 
	//���űպ�����
	i = 0;
	count = 0; 
	while(i<strlen(str)){
		if(str[i]=='(') count++;
		else if(str[i]==')') count--;
		
		if(count<0) return false;
		i++;
	} 
	if(count!=0){
		cout<<"buckets error"<<endl;
		return false;
	}
	
	return true; 
}

//�������Ϸ��� a=sin(3X^2)
bool check_tri(char * str){
	//�����str�����Ǻ��������е����ݣ���sin(3X^2+(X^X))�е� 3X^2+(X^X)
	return check(str);	
}

void throw_error1(){
	cout<<"invalid character"<<endl;
}
void throw_error2(){
	cout<<"invalid expression"<<endl;
}

int main(){
    char str[50],a;
    char formula[70];
    cin.getline(str,50);
//  cout<<str<<endl;
//	cout<<strlen(str)<<endl;
	
	//��������ַ����� 
	for(int i=0;i<strlen(str);i++){
		a = str[i];
		if(a=='X'||a=='+'||a=='-'||a=='*'||a=='/'||a=='^'||a=='('||a==')'||(a>='0'&&a<='9')||a=='.'){}
		else{
			throw_error1();
			return 0;
		}
	}
	if(!check(str)){
		throw_error2();
		return 0;
	}
//	cout<<"check succeeded"<<endl; 
	cout<<replace_x(str, formula, 10);
//	calc(str,10);
    return 0;
}


















