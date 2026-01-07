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
    
    for(i=1;i<n;i++)
    {
    	int key=a[i];
    	int j=i-1;
    	
    	while(j>=0 && a[j]>key)
    	{
    		a[j+1]=a[j];
    		j--;
		}
		a[j+1]=key;
	}
	cout<<"Sorted array using insertion sorting:\n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}