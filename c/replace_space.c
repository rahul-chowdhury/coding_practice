#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int i,end,newend,no_of_spaces=0;
	printf("enter string :");
	gets(str);
	end=strlen(str);
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]==' ')
		{
			no_of_spaces++;
		}
	}
	newend=strlen(str)+no_of_spaces*2;
	printf("%d %d %d\n",end,newend,no_of_spaces);
	str[newend]='\0';
	
	for(i=end-1;i>=0;i--)
	{
		if(str[i]==' ')
		{
			str[newend-1]='0';
			str[newend-2]='2';
			str[newend-3]='%';
			newend -=3;
		}
		else
		{
			str[newend-1]=str[i];
			newend--;
		}
	}
	printf("%s\n",str);
	return 0;
}
