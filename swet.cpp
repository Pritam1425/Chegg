#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int flag = 1;
	int c1=0,c2=0,r1=1,r2=4;
	while(1){
		if(flag==1){
			if(r1<=n){
				c1+=r1;
				n-=r1;
				r1 = r1*9;
			}
			flag = 2;
		}
		else{
			if(r2<=n){
				c2+=r2;
				n-=r2;
				r2 = r2*16;
			}
			flag = 1;
		}
		if(r1>n&&r2>n)
		break;
	}
	cout<<c1<<" "<<c2;
	return 0;
}
