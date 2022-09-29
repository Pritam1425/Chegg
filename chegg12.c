#include<stdio.h>
struct visitor{
	char name[100];
	int age;
	char cls;
	float price;
};
void printDash(int n)//Printing dashes for the output
{
	int i;
	for(i=0;i<n;i++)
		printf("-");
}

void main()
{
	printDash(40);
	printf("\n");
	printf("Formula Race Ticket Reservation System\n");
	printDash(40);
	printf("\n");
	
	int n,i;//n=total visitors,i=for loop iteration
	float totalPrice=0;//Variable to store total price of the tickets
	
	printf("Enter Number of Visitors: ");
	scanf("%d",&n);
	
	struct visitor arr[n];//store all the details of visitors in array arr
	
	for(i=0;i<n;i++){
		printf("Name of visitor %d: ",i+1);
		scanf("%s",arr[i].name);
		printf("Age of visitor %d: ",i+1);
		scanf("%d",&arr[i].age);
		printf("Class of visitor %d: ",i+1);
		scanf(" %c",&arr[i].cls);
		
		//Storing the prices of the tickets for visitors
		if(arr[i].cls=='A'){
			if(arr[i].age<18){//To store the discounted ticet price if age<18
				arr[i].price = 1500*0.9;
			}
			else {
				arr[i].price = 1500;
			}
		}
		else if(arr[i].cls=='B'){
			if(arr[i].age<18){
				arr[i].price = 1200*0.9;
			}
			else {
				arr[i].price = 1200;
			}
		}
		else{
			if(arr[i].age<18){
				arr[i].price = 800*0.9;
			}
			else {
				arr[i].price = 800;
			}
		}
		
		totalPrice += arr[i].price;//Here we are adding the ticket prices
	}
	
	printDash(101);
	printf("\n\n");
	printDash(42);
	printf(" Visitors Report ");
	printDash(42);
	printf("\n\n");
	printDash(101);
	printf("\n\n");
	
	//Some string for the output
	char className[3][30] = {"Central Grandstand C", "Central Grandstand B","Central Grandstand A"};
	char str[5][20] = {"Visitor ID","Visitor Name","Visitor Age","Class","Price"};
	
	//%-20s here the minus makes it left alligned and 20 is the total space for printing the value
	printf("%-20s %-20s %-20s %-25s %-20s\n",str[0],str[1],str[2],str[3],str[4]);
	
	for(i=0;i<n;i++){
		// printing ID,name,age,full class name,price
		printf("%-20d %-20s %-20d %-25s %-20.2f\n\n",i+1,arr[i].name,arr[i].age,className['C'-arr[i].cls],arr[i].price);
	}
	//printing total price of the tickets
	printf("\n\nTotal prices of all tickets: %.2f\n",totalPrice);
	printf("Thank you for using our Ticket reservation system!!\n");
}
