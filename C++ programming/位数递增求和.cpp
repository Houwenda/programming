using namespace std;
#include <iostream>
#include <cmath>
int main()
{
	long a,n,i=1,j=0,k,sum,sumw;  //iΪ������jΪλ�� 
	cin>>a>>n;
	while(i<=n)
	{
		j=1;
		while(j<=i)
		{
			k=1;
			sumw=a;
			while(k<j)
			{
				sumw=sumw*10;
				k++;
			}
			sum+=sumw;
			j++;
		}
		i++;
	}
	cout<<sum;
	return 0;
}
