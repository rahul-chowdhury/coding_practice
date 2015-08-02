#include<iostream>
#include<limits.h>
using namespace std;

struct node
{
	int length,value;
	struct node *prev;
};

int main()
{
	int a[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(a)/sizeof(a[0]),globalmax=INT_MIN;
    struct node lis[n],*global_pointer,*temp;
    for(int i=0;i<n;i++)
    {
    	lis[i].length=1;
    	lis[i].value=a[i];
    	lis[i].prev=NULL;
    	int max=0;
    	struct node *pointer=NULL;
    	for(int j=0;j<i;j++)
    	{
    		
    		if(a[i]>a[j] && max<lis[j].length)
    		{
    			pointer=&lis[j];
    			max=lis[j].length;
    			
    		}
    	}
    	if(max>globalmax)
    	{
    		globalmax=max+1;
    		global_pointer=&lis[i];
    	}
    		
    	if(max>0)
    	{
    		lis[i].length=max+1;
    		lis[i].prev=pointer;
    	}
    }
    cout<<"LIS : ";
    temp=global_pointer;
    while(temp!=NULL)
    {
    	cout<<temp->value<<" ";
    	temp=temp->prev;
    }
    cout<<endl;
    return 0;
  }
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		