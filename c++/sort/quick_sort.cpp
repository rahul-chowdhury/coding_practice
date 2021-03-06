#include <bits/stdc++.h>
using namespace std;

int partition(int *a,int low,int high)
{
	//int pivot=a[pivot_index];
	int pivot=a[low];
	int start=low,end=high;
	while(start<end)
	{
		while(start<=high && a[start]<=pivot)
		{
			start++;
		}
		while(end>=low && a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			int temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}
	}
	//a[pivot_index]=a[end];
	a[low]=a[end];
	a[end]=pivot;
	return end;
}

int randomized_partition(int *a,int low,int high)
{
	srand(time(NULL));
	int random_index=(rand()%(high-low+1))+low;
	int temp=a[random_index];
	a[random_index]=a[low];
	a[low]=temp;
	//cout<<random_index<<endl;
	return partition(a,low,high);
}

void quick_sort(int *a,int low,int high)
{
	if(low<high)
	{
		int mid=randomized_partition(a,low,high);
		cout<<"pivot element: "<<a[mid]<<endl;
		
		quick_sort(a,low,mid-1);
		quick_sort(a,mid+1,high);
	}
}

int main()
{
	int a[]={2,4,56,77,8,99,0,-112};
	quick_sort(a,0,sizeof(a)/sizeof(int)-1);
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
















