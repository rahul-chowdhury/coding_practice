#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],temp;
	int x=0,i,j;
	printf("enter string :");
	scanf("%s",str);
	
	for(i=0;i<strlen(str);i++)
	{
		for(j=0;j<x;j++)
		{
			if(str[i]==str[j])
				break;
		}
		if(x==j)
		{
			str[x]=str[i];
			x++;
		}
	}
	str[x]='\0';
	printf("%s\n",str);
	return 0;
}