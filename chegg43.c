#include<stdio.h>
#include<stdarg.h>
int add(int args, ...){
	va_list ap;
	va_start(ap,args);
	
	int i=0,sum=0;
	for(i = 0; i <args; i++){
		sum+=va_arg(ap,int);
	}
	
	va_end(ap);
}
void main()
{
	printf("%d\n",add(5,6,7,8,9,10));
}
