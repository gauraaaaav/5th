#include<iostream>
using namespace std;
int fibo(int i)
{
	if(i==0||i==1)
	return i;
	else
	return fibo(i-1)+fibo(i-2);
}
int main()
{
	int n,i;
	cout<<"Enter the nth term:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<fibo(i)<<"\n";
	}
}