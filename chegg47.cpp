#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;
class myArray
{

private :

int siz;
int *arr;//array as pointer for dynamic memory
public:
myArray()
{
siz=0;
}
myArray(int s)
{
arr=new int[s];//allocating size to array
siz=s;
}
myArray(const myArray& s){//Implemented copy constructor
	siz = s.siz;
	arr = s.arr;
}
~myArray()
{
delete arr; //deallocating Memory

}


//taking input from user to store in array
void store()
{

for(int i=0;i<siz;i++)
{
cout<<"Enter Number\t:\t";
cin>>arr[i];
}
}

//store 1000 random number in array
void storeRand()
{
srand(time(0)); // Initialize random number generator.
siz=1000;//for storing 1000 random number
arr=new int[siz];
cout<<"Random numbers generated between 1 and 10000:"<<endl;
for(int i=0;i<1000;i++)
arr[i]=(rand() % 10000) + 1;//storing random number between 1-10000

}

//get size of array
int getSize()
{
return siz;
}

//display array 10 column wise
void Display()
{

for(int i=0;i<siz;i++)
{
for ( int j=1;j<=10;j++)// 10 column in one row
{
cout<<arr[i++]<<"\t";
if(siz==i)// if array is less than of 10
break;
}
cout<<endl;
}
}

//adding number at start
void addStart(int n)//Implemented new addstart
{
siz++;//increasing array size
int* newarr = new int[siz];//create a newarr and store the values of arr into it
for(int i=0;i<siz-1;i++){
	newarr[i+1] = arr[i];
}
newarr[0]=n;//inserting new element at start
arr = newarr;
}

//adding number at end
void addEnd(int n)//Implemented new addEnd
{

siz++;//increasing array size
int* newarr = new int[siz];
for(int i=0;i<siz-1;i++){//create a newarr and store the values of arr into it
	newarr[i] = arr[i];
}
newarr[siz-1]=n;//inserting new element at start
arr = newarr;
}

//remove element from start
void removeStart()
{
int i;
for(i=0;i<siz-1;i++)
{
arr[i]=arr[i+1];// moving element up

}
arr[i]=0;
siz--;//decrease the array size;
}

//remove from end
void removeEnd()
{
arr[siz-1]=0;
siz--;//decrease the array size
}


//inverse of array
void Inverse()
{
Sort();
//inverse is Simply swapping the value of the array with the value at that index.
int inver[siz];
for(int i = 0;i < siz;i++){

inver[arr[i]] = i;
}
for(int i = 0;i < siz;i++)
{
cout<<endl<<arr[i]<<" -----> "<< inver[arr[i]];
}
}


//sorting of an array
void Sort()
{

for(int i=0;i<siz-1;i++)
{

for(int j=i+1;j<siz;j++)
{

if(arr[i]>arr[j])
{
int temp =arr[i];
arr[i]=arr[j];
arr[j]=temp;
}

}
}

}

//sum of elements
int sumEle()
{
int sum=0;
for(int i=0;i<siz;i++)
{
sum=sum+arr[i];//Sum of array elements

}
return sum;
}


//odd array
myArray OddArr()
{
myArray od;
for(int i=0;i<siz;i++)
{
if(arr[i]%2!=0)//checking for odd numbers
od.addEnd(arr[i]);//storing odd number in the end
}
return od;
}

//linear search
int FindLinear(int n)
{
int found=-1;

//linear search
//it will check element one by one it is slow process as it check all till not match
for(int i=0;i<siz;i++)
{
if(arr[i]==n)//if number match
{
found=1;// found
return i;

}

}
if(found==-1)
{
cout<<"Not found";
return -1;
}
return 0;
}

//binary search
int FindBinary(int n)
{
Sort();
int l=0,r=siz-1,x=n;// l is lower bound , r is upper bound,x is the value for search
// it is binary search, it is done on sorted data and is faster than linear search because it searched array by divide the array into two subarrays
while (r >= l)
{
int mid = l + (r - l) / 2;

// If the element is present at the middle
// itself
if (arr[mid] == x)
return mid;

// If element is smaller than mid, then
// it can only be present in left subarray
if (arr[mid] > x)
r=mid-1;
else
l=mid+1;
// Else the element can only be present
// in right subarray

}

// We reach here when element is not
// present in array
return -1;

}
};


//main program
int main()
{
int s;

//Random Number
myArray m1;
m1.storeRand();
m1.Display();

//new array with user given size and input

cout<<"\n\n------------------------------------------------------------------------------------\nEnter Array Size\t:\t";
cin>>s;

myArray m(s);
m.store();
m.Display();

// adding element at beginning
cout<<"\n-----------------------------------Add Item at Start-----------------------------------\n";
m.addStart(-80);//adding -80 at start
m.Display();
getch();

cout<<"\n-----------------------------------Add Item at end-------------------------------\n";
//adding element at end
m.addEnd(-100);//add -100 at end
m.Display();
getch();

cout<<"\n-----------------------------------Remove Item From Start------------------------------\n";
//removing from starting
m.removeStart();
m.Display();

cout<<"\n----------------------------------------Remove Item From End--------------------\n";
//removing from end
m.removeEnd();
m.Display();

cout<<"\n-----------------------------------------Inverse of Array------------------------\n";
m.Inverse();
// m.Display();
cout<<"\n------------------------------------------------------------------------------------\n";
cout<<"\nSum of elements\t:\t"<<m.sumEle();
cout<<"\n------------------------------------------------------------------------------------\n";
getch();
cout<<"\nOdd Array\n";
myArray od=m.OddArr();//Copy constructor is needed here
od.Display();
getch();
cout<<"\n-------------------------------Sorted Array-----------------------------------\n";
m.Sort();
m.Display();
cout<<"\n------------------------------------------------------------------------------------\n";
cout<<"Enter element to search";
cin>>s;


//using linear search
cout<<"\nUsing Linear Search Element is at\t:\t"<<m.FindLinear(s);
//binary search
cout<<"\nUsing Binary Element is at\t\t:\t"<<m.FindBinary(s);

}
