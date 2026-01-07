#include <iostream>
using namespace std;

int main() {
    int i,j,n, a[50],temp;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for ( i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for( i=0;i<n-1;i++)
    {
    	int min=i;
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[j]<a[min])
    		min=j;
		}
		int temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	
	cout<<"Sorted array using selection sorting:\n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}