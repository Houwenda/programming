using namespace std;
#include <iostream>
int gcd(int a, int b)  //���Լ�� 
{
	int r;
	r=a%b;
	if(r==0) return b;
	else gcd(b,r);
}
	int lcm(int a, int b)  //��С������ 
	{
		return a*b/gcd(a,b);
	}
int main()
{
	int a,b; 
	cin>>a>>b;
	cout<<"���Լ��Ϊ"<<gcd(a,b)<<'\n'<<"��С������Ϊ"<<lcm(a,b);
	return 0;
}
