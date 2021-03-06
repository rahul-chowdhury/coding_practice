#include <bits/stdc++.h>
using namespace std;

void merge(int *a,int low,int mid,int high)
{
	int left[mid-low+1],right[high-mid],left_index=0,right_index=0,left_length=mid-low+1,right_length=high-mid,index=low;
	for(int i=low;i<=mid;i++)
	{
		left[left_index++]=a[i];
	}
	for(int i=mid+1;i<=high;i++)
	{
		right[right_index++]=a[i];
	}
	left_index=right_index=0;
	while(left_index!=left_length || right_index!=right_length)
	{
		if(left_index==left_length)
		{
			while(right_index!=right_length)
			{
				a[index++]=right[right_index++];
			}
			break;
		}
		else if(right_index==right_length)
		{
			while(left_index!=left_length)
			{
				a[index++]=left[left_index++];
			}
			break;
		}
		else if(left[left_index]<right[right_index])
		{
			a[index++]=left[left_index++];
		}
		else
		{
			a[index++]=right[right_index++];
		}
	}
}	

void merge_sort(int *a,int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		//cout<<"pivot element: "<<a[mid]<<endl;
		
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int main()
{
	clock_t t1=clock();
	int a[]={2,4,-56,77,8,99,0,-12,3,54,78,245,7,454,8976,3,3,35,2,-5,24,54,776};
	merge_sort(a,0,sizeof(a)/sizeof(int)-1);
	cout<<clock()-t1<<endl;
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
















