#include<iostream>
#include<stdlib.h>
#include <time.h> 
using namespace std;

int partition(int a[],int p,int r)
{
	int x=a[p],i=p,j=r;
	
	while(i<j)
	{
		while(j>=p && a[j]>x)
		{
			j--;
			
		}
		while(i<=r && a[i]<=x)
		{
			i++;
		}
		if(i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		
	}
	a[p]=a[j];
	a[j]=x;
	//cout<<"j="<<j<<endl;
	//for(int i=0;i<r-p+1;i++)
	//{	cout<<a[i]<<" ";
	//}
	//cout<<"here"<<endl;
	return j;
}

int random_select(int a[],int p,int r)
{
	int q=rand()%(r+1);
	int temp=a[q];
	a[q]=a[0];
	a[0]=temp;
	int x=partition(a,p,r);
	//cout<<"j="<<x<<endl;
	return x;
}

void quicksort(int a[],int p,int r)
{
	if(p<r)
	{
		int q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

void random_quicksort(int a[],int p,int r)
{
	if(p<r)
	{
		int q=random_select(a,p,r);
		random_quicksort(a,p,q-1);
		random_quicksort(a,q+1,r);
	}
}
int compare(const void *a,const void *b)
{
	int *a1=(int *)a;
	int *b1=(int *)b;
	return *a1-*b1;
}	
int main()
{
	int n,low,high,mid,x,begin,end;
	clock_t timer1,timer2,timer3,timer4;
	cout<<"no. of elements :";
	cin>>n;
	int a[n];
	//cout<<"enter elements :";
	for(int i=0;i<n;i++)
	{//cout<<"enter element "<<i<<":";
	//cin>>a[i];
	a[i]=rand();
	}
	timer1 = clock();
	qsort(a,n,sizeof(int),compare);
	timer2 = clock();
	quicksort(a,0,n-1);
	
	timer3 = clock();
	random_quicksort(a,0,n-1);
	timer4 = clock();
	cout<<"system quick sort :"<<float( timer2-timer1) /  CLOCKS_PER_SEC<<endl;
	cout<<"my hoare quick sort :"<<float( timer3-timer2) /  CLOCKS_PER_SEC<<endl;
	cout<<"my random quick sort :"<<float( timer4-timer3) /  CLOCKS_PER_SEC<<endl;
	
	/*for(int i=0;i<n;i++)
	{	cout<<a[i]<<" ";
	}
	cout<<"enter element whose frequency to be searched :";
	cin>>x;
	low=0,high=n-1;
	while(low<high)
	{
		mid=(low+high)/2;
		if(a[low]==x && (low==0 || a[low-1]!=x))
		{
			
			break;
		}
		if(a[mid]==x && (mid==0 || a[mid-1]!=x))
		{
			low=mid;
			break;
		}
		if(x<=a[mid])
		high=mid;
		else
		low=mid+1;
		 
	}
	begin=low;
	low=0,high=n-1;
	while(low<high)
	{
		mid=(low+high)/2;
		if(a[high]==x && (high==n-1 || a[high+1]!=x))
		{
			
			break;
		}
		if(a[mid]==x && (mid==0 || a[mid+1]!=x))
		{
			high=mid;
			break;
		}
		if(x>=a[mid])
		low=mid;
		else
		high=mid-1;
	}
	end=high;
	
	cout<<"length="<<end-begin+1<<endl;*/
		
	return 0;
}
