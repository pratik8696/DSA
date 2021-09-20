#include <iostream>
using namespace std;
int increment(int[],int);
int main(){
	int n;
	cin>>n;
	int array[n];
	for (int i = 0; i < n; i++)
	{
		cin>>array[i];
	}
	increment(array,n);
	return 0;
}
int increment(int a[],int n){
	for (int i = 0; i < n; i++)
	{
		a[i]=a[i]*2;
	}
}