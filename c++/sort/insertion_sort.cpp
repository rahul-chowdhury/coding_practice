#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int *a,int low,int high)
{
	int min,temp,j;
	for(int i=low+1;i<=high;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=low && a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
		
	}
}

int main()
{
	int a[]={2,4,56,77,8,99,0,-112};
	insertion_sort(a,0,sizeof(a)/sizeof(int)-1);
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
