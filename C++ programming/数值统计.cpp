/*
using namespace std;
#include <iostream>

int main(){
	
	int n,a,b,c,i;
	while(cin>>n){
		
		if(n<=0){
			return 0;
		}
		a = 0;
		b = 0;
		c = 0;
		i = 0;
		while(i<n){
			double* num = NULL;
			num = new double;
			cin>>*num;
			if(*num<0) a++;
			else if(*num==0) b++;
			else if(*num>0) c++;
			
			delete num;	
			i++;				
		}
	
		cout<<a<<' '<<b<<' '<<c<<endl;			
		
	}
	
	
	return 0;
}
*/ 
using namespace std;
#include <iostream>

int main(){
	int n;
	double num[100];
	while(cin>>n){
		if(n<=0) return 0;
		int a=0;
		int b=0;
		int c=0;
		for(int i=0;i<n;i++) cin>>num[i];
		for(int i=0;i<n;i++){
			if(num[i]<0) a++;
			else if(num[i]==0) b++;
			else if(num[i]>0) c++;
		}
		cout<<a<<' '<<b<<' '<<c<<endl;
	}
	return 0;
}
