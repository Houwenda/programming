using namespace std;
#include <iostream>
#include <cstring>
int whichnum(int a[],int m)
{
	int i=0;
	for(;i<m;i++) 
	if(a[i]!=-1) 
	return i;	
} 




bool numleft(int a[],int m)  //�ж�a���Ƿ�ֻʣһ�� 
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
	int i,j=0,k=0,a[m],b[n],num;
	for(i=0;i<m;i++) a[i]=i+1;
	memset(b,0,sizeof(b)); 
	
	while(numleft(a,m),m)  //a�в�ֹһ��ʱ 
	{
		while(j!=m)  //aû�й���ʱ 
		{
			while(k!=n)  //bû�й���ʱ 
			{
				if(a[j]!=-1)  //a[j]δ���ų� 
				{
					b[k]=a[j];
					k++;
					j++;
					if(j==m) break;
				}
				else 
				{
					j++;  //a[j]�ѱ��ų� 
					if(j==m) break;	
				} 
			//b����ʱ
			k=0; 
			a[j-1]=-1;  //�ų���n�� 
			if(~numleft(a,m),m) 
			{
				num=whichnum(a,m);  //ʣ���һ�����
				return num;
			}
			} 		
		//a����� 
		j=0;  //Χ��Ȧ		
		}
	}
	
}



int main()
{
	int m,n;
	cin>>m>>n;
	cout<<game(m,n);
	return 0;
} 
