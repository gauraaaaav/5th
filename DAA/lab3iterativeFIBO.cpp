#include<iostream>
using namespace std;
int main()
{
	int n,temp=1,a=0,b=1,c;
	cout<<"Enter the nth term:";
	cin>>n;
	if(n<=0)
	return 0;
	cout<<a<<"\n";
	
	if(n<=1)
	return 0;
	cout<<b<<"\n";
	
	while(temp!=n-1)
	{
		c=a+b;
		cout<<c<<"\n";
		a=b;
		b=c;
		temp++;
	}
}