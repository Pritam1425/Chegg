#include<stdio.h>
void prepareData(int data0[],int data1[],int data2[],int size0)
{
	int t0=0,t1=0,t2=0,t9=2;
	
	while(t0<size0){//loop condition
		int t4 = data0[t0];//Store the data[t0] into t4 for further calculation
		int  t3 = t4%t9;//mfhi stores the remainder when div $t4,$t9 is called
		if(t3!=0){//label 2 when t3!=0
			data1[t1] = t4;
			t1++;
		}
		else {//when t3!=0 continue the program
			data2[t2] = t4;
			t2++;
		}
		//label 3
		t0++;
	}
}
int processData(int data1[],int size12)
{
	int t0=0,t1=100,t9=2;
	while(t0<size12){//loop condition
		int t4 = data1[t0];//Store the data1[t0] into t4 for further calculation
		int t3 = t0%t9;//mfhi stores the remainder when div $t0,$t9 is called
		if(t3!=0){//label6 when t3!=0
			t1 -= t4;
		}
		else {//when t3!=0 continue the program
			t1 += t4;
		}
		//label7
		t0++;
	}
	//label 8 return the result
	return t1;
}
displayResult(int s5,int s6,char* msg0,char* msg1,char* msg2)
{
	int t0 = s5+s6;
	printf("%s\n",msg0);
	printf("%s\n",msg1);
	printf("%s\n",msg2);
	printf("%d\n",t0);
}
int main()
{
	char msg0[] = "Assignment 3",msg1[] = "------------",msg2[] = "Result: ";
	int data0[] = {35,-34,82,-95,-2,22,-17,80,-67,-39,64,94,-96,95,-70,-63,69,-3,75,-10};//data0 an array of 20 integers
	int data1[10],data2[10],size0 = 20,size12 = 10;//data1 and data2 are arrays of 10 integers, size0 is size of data0 and size12 is size of data1 and data2
	
	prepareData(data0,data1,data2,size0);//prepare the data by sending data0,data1,data2,size into the function
	
	int s5 = processData(data1,size12);//process data1 and return the output
	
	int s6 = processData(data2,size12);//process data2 and return the output
	
	displayResult(s5,s6,msg0,msg1,msg2);//display the result by passing outputs of the processData functions and the messages
	return 0;
}
