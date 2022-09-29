#include <iostream>
#include <fstream>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;

const int size = 50;

class maintHist {
public:
   string maintDate;
   string maintType;
   string maintMech;
   maintHist();
   ~maintHist();
};

class bus {
private:
   string busID;
   string manufacturer;
   int capacity;
   int mileage;
   char status;
public:
   bus();
   maintHist *maintHistPointerToArr; //Pointer that points to maintHistArr[25]
   int numMH;
   void operator=(bus &);
   bool operator==(bus &);
   bool operator>(bus &);
   ~bus();

   static int counter;
   void setBusID(string);//setters
   void setManufacturer(string);
   void setCapacity(int);
   void setMileage(int);
   void setStatus(char);
   string getBusID();//getters
   string getManufacturer();
   int getCapacity();
   int getMileage();
   char getStatus();
};

bool bus::operator==(bus &RHS)
{
   if (this->numMH == RHS.numMH)
   {
       return true;
   }
   else
   {
       return false;
   }
}
bool bus::operator>(bus &RHS)
{
   if (this->numMH > RHS.numMH)
   {
       return true;
   }
   else
   {
       return false;
   }
}
void bus::operator=(bus &RHS)
{
   this->manufacturer = RHS.manufacturer;
   this->capacity = RHS.capacity;
   this->mileage = RHS.mileage;
}
bus::bus()//constructor called for all 50 buses
{
   numMH = 0;
   maintHistPointerToArr = new maintHist[25];
}
bus::~bus()
{
   cout << "destructing" << endl;
   for(int i=0;i<numH;i++){
   	
   }
}


void bus::setBusID(string ID)
{
   busID = ID;
}
void bus::setManufacturer(string manu)
{
   manufacturer = manu;
}
void bus::setCapacity(int cap)
{
   capacity = cap;
}
void bus::setMileage(int miles)
{
   mileage = miles;
}
void bus::setStatus(char stat)
{
   status = stat;
}
string bus::getBusID()
{
   return busID;
}
string bus::getManufacturer()
{
   return manufacturer;
}
int bus::getCapacity()
{
   return capacity;
}
int bus::getMileage()
{
   return mileage;
}
char bus::getStatus()
{
   return status;
}

void displayCH();
void displayBus(bus);

int bus::counter;

int main() {
   ifstream inFile;
   bus arr[size];
   string input, ID, manu, statu, input2, input3;
   int cap, miles;
   char stat, transCode;
   inFile.open ("C:/Users/graye/Downloads/a4data.txt", ios::in);
   if (inFile.is_open())
   {
       getline(inFile, input);
       while (!inFile.eof())
       {
           ID = input.substr(0,5);
           manu = input.substr(5,10);
           cap = atoi(input.substr(15,3).c_str());
           miles = atoi(input.substr(18,7).c_str());
           statu = input.substr(25,1);
           stat = statu[0];
           arr[bus::counter].setBusID(ID);
           arr[bus::counter].setManufacturer(manu);
           arr[bus::counter].setCapacity(cap);
           arr[bus::counter].setMileage(miles);
           arr[bus::counter].setStatus(stat);
           bus::counter++;
           getline(inFile, input);
       }
       inFile.close();
   }
   else
   {
       cout << "Error, file failed to open.";
       return 1;
   }
   displayCH();
   for (int i = 0; i < bus::counter; i++)
   {
       displayBus(arr[i]);
   }
   cout << "---end of list---" << endl;
   cout << "Enter transaction code (M, L, C, N, D, X=exit)" << endl;
   getline(cin, input);
   transCode = toupper(input[0]);
   while (transCode != 'X')
   {
       int k = bus::counter;
       k -= 1;
       if (transCode == 'M')
       {
           cout << "Enter bus ID" << endl;
           getline(cin, input2);
           for (int i = 0; i < bus::counter; i++)
           {
               if (input2 == arr[i].getBusID())
               {
                   cout << "Enter maintenance date\n";
                   getline(cin, input3);
                   arr[i].maintHistPointerToArr[arr[i].numMH].maintDate = input3;
                   cout << "Enter maintenance type\n";
                   getline(cin, input3);
                   arr[i].maintHistPointerToArr[arr[i].numMH].maintType = input3;
                   cout << "Enter maintenance mechanic\n";
                   getline(cin, input3);
                   arr[i].maintHistPointerToArr[arr[i].numMH].maintMech = input3;
                   arr[i].numMH++;
                   cout << "Maintenance element added to bus " << input2 << endl;
                   break;
               }
               else if (i == k)
               {
                   cout << "Bus not found" << endl;
               }
           }
       }
       else if (transCode == 'L')
       {
           cout << "Enter bus ID" << endl;
           getline(cin, input2);
           for (int i = 0; i < bus::counter; i++)
           {
               if (input2 == arr[i].getBusID())
               {
                   cout << "Start of maintenance history\n";
                   for (int j = 0; j < arr[i].numMH; j++)
                   {
                       cout << setw(20) << "history element " << j << " - " << arr[i].maintHistPointerToArr[j].maintDate << ", " << arr[i].maintHistPointerToArr[j].maintType << ", " << arr[i].maintHistPointerToArr[j].maintMech << endl;
                   }
                   cout << "End of history for bus " << input2 << endl;
                   break;
               }
               else if (i == k)
               {
                   cout << "Bus not found" << endl;
               }
           }
       }
       cout << "Enter transaction code (M, L, C, N, D, X=exit)" << endl;
       getline(cin, input);
       transCode = toupper(input[0]);
   }
   cout << "Thank you and have a nice day!" << endl;
   return 0;
}
