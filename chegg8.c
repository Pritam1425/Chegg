#include<stdio.h>
#define MAX_LEN 1000
void main()
{
	char str[MAX_LEN];
	scanf("%[^\n]s",str);
	
	printf("%s ,%d",str,strlen(str));
}
