#include<bits/stdc++.h>
using namespace std;

int maximum(int a,int b,int c)
{
	if(a>b && a>c)
		return a;
	if(b>c)
		return b;
	return c;
}

int max_sum_contiguous_subsequence(int *a,const int &n)
{
	
	int max[n];
	if(n>=1)
		max[0]=a[0];
	if(n>=2)
		max[1]=maximum(a[0],a[1],a[0]+a[1]);
	if(n>=3)
		max[2]=maximum(a[2]+max[1],max[1],a[2]+max[0]);
	for(int i=3;i<n;i++)
	{
		max[i]=maximum(a[i]+a[i-1]+max[i-3],max[i-1],a[i]+max[i-2]);
	}
	return max[n-1];
}

int main()
{
	int a[]={-2,11,-4,13,-5,2};
	cout<<"max sum is "<<max_sum_contiguous_subsequence(a,sizeof(a)/sizeof(int))<<endl;
	
	return 0;
}

	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
				
