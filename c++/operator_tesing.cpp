#include<stdio.h>
#include<stdlib.h>
static int value;
struct test
{
	int a;
	//char ch;
};
int main()
{
	
	printf("%d\n",sizeof(struct test));
	/*printf("%s\n",_DATE_);
	printf("%s\n",_FILE_);
	printf("%s\n",_LINE_);printf("%s\n",_LINE_);
	printf("%s\n",_TIME_);*/
	return 0;
}

