using namespace std;
#include <iostream>
#include <cstring>
bool numleft(int a[])
{
	int i=0,j=0;
	while(i<m)
	{
		if(a[i]!=-1) j+=1;
		i++;
	}
	if(j=1) return false; //a��ֻʣһ�� 
	else return true;  //a�л�ʣ��� 
}
int game(int m,int n)
{
	int a[m],i,j=0,b[n];
	for(i=0;i<m;i++) a[i]=i+1;
	while(numleft(a))  //a�л�ʣ��� 
	{
		memset(b,0,sizeof(b));
		while(b[n-1]==0)  //bδ������ 
		{
			for(;j<m;j++) 
			{
				if(a[j]!=-1) b[j]=a[j];  //��a�з�-1�ı�ŷ���b�� 
				else continue;			
			}
			if(j==m) j=0;  //Χ��һ��Ȧ		
		}
		a[j]=-1;  // 
	}	 
	ruturn 
}
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<game(m,n);
	return 0;
}
