#include<iostream>
#include<limits.h>
using namespace std;


int main()
{
	int n,tempmax,tempstart,tempend,tempsum,start,end;
	cout<<"enter n:";
	cin>>n;
	int a[n];
	cout<<"enter elements:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum[n];
	int max[n];
	max[0]=a[0];
	sum[0]=a[0];
	start=end=0;
	for(int i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<n;i++)
	{
		int tempmax=INT_MIN;
		for(int j=0;j<=i;j++)
		{
			if(j==0)
				tempsum=sum[i];
			else
				tempsum=sum[i]-sum[j-1];
			if(tempsum>tempmax)
			{
				tempmax=tempsum;
				tempstart=j;
				tempend=i;
			}
		}
		if(tempmax>max[i-1])
		{
			max[i]=tempmax;
			start=tempstart;
			end=tempend;
		}
		else
			max[i]=max[i-1];
	}
	cout<<"i="<<start<<" j= "<<end<<" sum= "<<max[n-1]<<endl;
	return 0;
}	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		