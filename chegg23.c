#include<stdio.h>
void main()
{
	char ch;
	while(ch = getch()!=EOF){
		printf("hi %c",ch);
	}
}
