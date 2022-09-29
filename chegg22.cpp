#include<iostream>
#include<fstream>
#include<string>
using namespace std;
float salary(int hour,float rate)//Computing salary using weekly hour and rate
{
	//Monthly salary = weekly hours*4*rate per hour. As there are 4 weeks.
	return (hour*4*rate);
}
int main()
{
	fstream file1,file2;//fstream stream class to write or read
	
	file1.open("Original.txt",ios::in);//open with reading ios::in
	file2.open("Copy.txt",ios::out);//open with writing ios::out
	
	string str;
	while(getline(file1,str)){//read file line by line
	
		file2<<str<<" ";//write employee name, id, weekly hours, rate in Copy.txt
		
		int hour;
		float rate;
		char* temp[10];
		sscanf(str.c_str(),"%s %s %s %d %f",temp,temp,temp,&hour,&rate);//To convert string to integer and float for rate and hour
		
		float sal = salary(hour,rate);//compute salary
		
		float tax;
		if(sal>2500.00){//Tax calculation that is given in the question
			tax = sal*.33;
		}
		else
			tax = sal*.24;
			
		float net = sal-tax;//Net salary = gross Salary-tax;
		file2<<sal<<" "<<tax<<" "<<net<<"\n";//writing gross salary,tax,net salary into Copy.txt
	}
	file2.close();//Closing the file2 Copy.txt to stop writing
	file2.open("Copy.txt",ios::in);//Opening the file2 Copy.txt to read
	while(getline(file2,str))
	{		
		cout<<str<<endl;
	}
	file1.close();
	file2.close();
	return 0;
}
