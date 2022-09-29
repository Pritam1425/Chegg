#include<iostream>
#include<string>
using namespace std;
class Employee
{
	private:
		string firstName,lastName;
		int employeeNo,hour;//No of hours worked is assumed to be integer.
		float wage,overtime;//wage rate and overtime rate is $/hour and float
	public:
		Employee(string fname,string lname,int eno,int hr,float wg,float ov){//constructor for class. Here we initialize the private variables
			firstName = fname;
			lastName = lname;
			employeeNo = eno;
			hour = hr;
			wage = wg;
			overtime = ov;
		}
		float Salary(){//Salary function to compute salary.
			if(hour>8){//No of hours work needed is to be 8 hours and above that it is overtime
				return (wage*8+((hour-8)*overtime));//So 8*wage will be basic pay and the rest (hour-8)*overtime will be overtime pay
			}
			else{//If the employee didnt work overtime
				return wage*hour;
			}
		}
		void print(){//Display the employee ID, first name and last name.
			cout<<employeeNo<<" "<<firstName<<" "<<lastName<<endl;
		}
};
int main()
{
	string firstName,lastName;
	int employeeNo,hour;
	float wage,overtime;
	//Testing the functions
	
	//Taking inputs of employee
	cout<<"Enter Employee ID: ";
	cin>>employeeNo;
	cout<<"Enter Employee First Name: ";
	cin>>firstName;
	cout<<"Enter Employee Last Name: ";
	cin>>lastName;
	cout<<"Enter no of hours worked: ";
	cin>>hour;
	cout<<"Enter wage rate($/hour): ";
	cin>>wage;
	cout<<"Enter overtime rate($/hour): ";
	cin>>overtime;
	
	//Creating object of type Employee
	Employee emp(firstName,lastName,employeeNo,hour,wage,overtime);
	
	//Compute salary of employee emp and displaying it.
	cout<<"\nSalary of the employee is: "<<emp.Salary()<<endl;
	
	//Displaying the employee's id,first name, last name
	cout<<"\nEmployee details:"<<endl;
	emp.print();
	return 0;
}
