#include<stdio.h>
void main()
{
	int quantity;//quantity of item bought
	double price;//unit price in OMR
	
	//Taking inputs
	printf("Enter bought quantity : ");
	scanf("%d",&quantity);
	printf("Enter the unit price in OMR : ");
	scanf("%lf",&price);
	
	//Total money to be paid = quantity*unit price
	double total = quantity*price;
	//Printing output
	printf("Total money to be paid : %g OMR",total);
}
