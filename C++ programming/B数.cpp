#include <iostream>
using namespace std;

int main()
{
	int b,p;																	//�������� 
	cout<<"Don't you have a little b number in your heart?(y=1/n=0)"<<'\n';		//��� 
	cin>>p;																		//���� 
	/*�ж�����*/ 
	if (p==1) 																	//���� 
	{
		cout<<"Then what's your b number?"<<'\n';  								 
		cin>>b;
		cout<<"Good!Your b number is    "<<b<<'\n';	
	}
	else if (p==0)																//���� 
	{
		cout<<"û�У�����ܰ���Ŷ��";
	}
	else																		//�������� 
	{
		cout<<"��";
		
	}
	return 0;
 } 
