#include<bits/stdc++.h>
using namespace std;

void heapify(int *a,int i,int n)//n is the length of the array
{
	int left_child_index=2*i+1,right_child_index=2*i+2,max_index=i,temp;
	if(left_child_index<n && a[left_child_index]>a[i])
	{
		max_index=left_child_index;
	}
	if(right_child_index<n && a[right_child_index]>a[max_index])
	{
		max_index=right_child_index;
	}
	if(i!=max_index)
	{
		temp=a[max_index];
		a[max_index]=a[i];
		a[i]=temp;	
		heapify(a,max_index,n);
	}
}

void build_heap(int *a,int n)
{
	for(int i=n/2;i>=0;i--)
	{
		heapify(a,i,n);
	}
}

void heap_sort(int *a,int n)
{
	int temp,n1=n;
	build_heap(a,n);
	for(int i=n-1;i>0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		n--;
		heapify(a,0,n);
	
	}
}
	
	
int main()
{
	int a[]={2,4,56,77,8,99,0,-112};
	heap_sort(a,sizeof(a)/sizeof(int));
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}	
	
	
	
	
	
	
		
