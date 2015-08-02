#include<iostream>
#include <vector>
#include<stdlib.h>
using namespace std;
bool finished=false;

void process_solution(vector<int> &a,int n)
{
	int k;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(a[k]==i )
				{
					break;
				}
				
			}
			if(k==j)
				cout<<"q";
			else
				cout<<" ";
		}
		cout<<endl;
	}
	finished=true;
	
	
}

bool is_a_solution(vector<int> &a,int k,int n,int start_column)
{
	if(start_column==(k+1)%n)
	{
		return true;
	}
	return false;

}

void generate_candidate_list(vector<int> &a,int k,int n,vector<int> &candidate_list,int *number_of_candidates,int start_column)		
{
	*number_of_candidates=0;
	
	for(int i=0;i<n;i++)
	{
		bool check=true;
		for(int j=start_column;a[j]!=-1;j=(j+1)%n)
		{
			if(i==a[j])
			{
				check=false;
				break;
			}
		}
		for(int j=start_column;a[j]!=-1;j=(j+1)%n)
		{
			if(abs(i-k)==abs(a[j]-j))
			{
				cout<<"here"<<i<<a[j]<<endl;
				check=false;
				break;
			}
		}
		if(check==true)
		{
			candidate_list[(*number_of_candidates)++]=i;
		}
	}
}
void backtrack(vector<int> &a,int k,int n,int start_column)
{
	if(is_a_solution(a,k,n,start_column))
	{
		process_solution(a,n);
		for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	}
	else
	{
		vector<int>candidate_list;
		candidate_list.resize(n);
		int number_of_candidates;
		k=(k+1)%n;
		generate_candidate_list(a,k,n,candidate_list,&number_of_candidates,start_column);
		
		for(int i=0;i<n;i++)
		cout<<candidate_list[i]<<" ";
		cout<<endl;
		for(int i=0;i<number_of_candidates;i++)
		{	
			
			a[k]=candidate_list[i];
			//make_move(a,k,n);
			backtrack(a,k,n,start_column);
			//unmake_move(a,k,n);
			if(finished==true)
			{
				return;
			}
		}
	}
}



int main()
{
	vector<int>a;
	int column,row;
	cout<<"enter column which you want to be filled: ";
	cin>>column;
	cout<<"enter row which you want to be filled: ";
	cin>>row;
	a.resize(8);
	a.assign(8,-1);
	a[column]=row;
	backtrack(a,column,8,column);
	return 0;
}
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
