#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

void print_tree(node *root)
{
	if(root==NULL)
	{
		return;
	}
	print_tree(root->left);
	cout<<root->data<<" ";
	print_tree(root->right);
}

node * insert_tree(node * root, node *newnode)
{
	if(root==NULL)
	{
		root=newnode;
		return root;
	}
	if(newnode->data<root->data)
		root->left=insert_tree(root->left,newnode);
	else
		root->right=insert_tree(root->right,newnode);
	return root;
}

bool delete_tree(node *root,int x)
{
	node *parent=root;
	while(root!=NULL && root->data!=x)
	{
		parent=root;
		if(root->data > x)
			root=root->left;
		else
			root=root->right;
	}
	if(root==NULL)
		return false;
	if(root->left==NULL && root->right==NULL)
	{
		if(parent->left==root)
			parent->left=NULL;
		else
			parent->right=NULL;
		return true;
	}
	else if(root->left==NULL)
	{
		if(parent->left==root)
			parent->left=root->right;
		else
			parent->right=root->right;
		return true;
	}
	else if(root->right==NULL)
	{
		if(parent->left==root)
			parent->left=root->left;
		else
			parent->right=root->left;
		return true;
	}
	else
	{
		node *temp=root->left;
		if(temp->right==NULL)
		{
			if(parent->left==root)
			{
				parent->left=temp;
				temp->right=root->right;
			}
			
			else
			{
				parent->right=temp;
				temp->right=root->right;
			}
			return true;
		}
		while((temp->right)->right!=NULL)
			temp=temp->right;
		root->data=(temp->right)->data;
		temp->right=(temp->right)->left;
		return true;
	}
}
	


int main()
{
	node *root=NULL;
	int choice;
	bool check=true;
	while(check)
	{
		cout<<"enter 1 for insert, 2 for delete, 3 to print tree, and 4 to exit:"<<endl;
		cin>>choice;
		if(choice==1)
		{
			node *newnode=(node *)malloc(sizeof(node));
			newnode->left=NULL;
			newnode->right=NULL;
			cout<<"enter data : ";
			cin>>newnode->data;
			root=insert_tree(root,newnode);
		}
		else if(choice==2)
		{
			int x;
			cout<<"enter element to be deleted :";
			cin>>x;
			bool found=delete_tree(root,x);
			if(!found)
				cout<<"element not found"<<endl;
		}
		else if(choice==3)
		{
			cout<<"tree : ";
			print_tree(root);
			cout<<endl;
		}
		else
		{
			check=false;
		}
	}		
	return 0;
}
