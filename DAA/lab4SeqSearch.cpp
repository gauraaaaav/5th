#include<iostream>
using namespace std;
int main()
{
	int a[10],n,i,key;
	cout<<"Enter the number of elements in your array:";
	cin>>n;
	cout<<"Enter the elements:";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<"Enter key to be searched:";
	cin>>key;
	int pos=-1;
	int comparisons=0;
	
	for(i=0;i<n;i++)
	{
		comparisons++;
		if(a[i]==key)
		{
		   pos=i;
		   break;
	}
}
	
	if(pos!=-1)
	cout<<"Key found at index "<<pos<<"\n";
	else
	
	cout<<"Searched key not found!";
	
	
	cout<<"Total comparisons="<<comparisons;
	

}
