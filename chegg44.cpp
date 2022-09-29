#include<iostream>
#include<vector>
using namespace std;
class ClubMember{		//ClubMember Class Design
	string name,phone;	//Private Data members needed to store the info
	int points;
	public:
		ClubMember(){	//Default Constructor
		}
		//Setters to set the private data members of object
		void setName(string name){//set name
			this->name = name;
		}
		void setPhone(string phone){//set phone number
			this->phone = phone;
		}
		void setPoints(int points){//set points
			this->points = points;
		}
		
		//Getters to get the private data members of object
		string getName(){	//get name
			return this->name;
		}
		string getPhone(){	//get phone number
			return this->phone;
		}
		int getPoints(){	//get points
			return this->points;
		}
};
class ClubManager{		//ClubManager class design
	vector<ClubMember>members;	//vector of ClubMember objects
	public:
		ClubManager(){	//Default Constructor
		}
		void addMember(string name,string phone,int points){//Add new members
			ClubMember temp;
			temp.setName(name);
			temp.setPhone(phone);
			temp.setPoints(points);
			members.push_back(temp);	//Append the new member into the vector
		}
		ClubMember search(string name){//Search the clubmembers by name
			vector<ClubMember>::iterator it;
			ClubMember temp;
			for(it=members.begin();it!=members.end();it++){
				temp = *it;
				if(temp.getName()==name){//If the name matches return the clubmember object temp
					return temp;
				}
			}
			ClubMember emp;//If we dont get such clubmember, we return empty object
			return emp;
		}
		void display(){		//Display all the clubmembers
			vector<ClubMember>::iterator it;
			for(it=members.begin();it!=members.end();it++){
				string name = it->getName();
				int points = it->getPoints();
				cout<<"Name:"<<name<<" \tPoints:"<<points<<"\n";
			}
		}
};
int main()
{
	//ClubManager object create
	ClubManager obj;
	
	//Adding the members
	obj.addMember("JK Rowling","(555) 555-1234",56);
	obj.addMember("Stephen King","(555) 555-1235",345);
	obj.addMember("John Grisham","(555) 555-1236",90);
	obj.addMember("George R.R. Martin","(555) 555-1237",200);
	obj.addMember("Lily King","(555) 555-1238",150);
	
	//searching the clubmembers using name
	string str = "Lily King";
	ClubMember obj2 = obj.search(str);//search obj using "Lily King"
	if(obj2.getName()!=""){//obj2.getName() = "Lily King", so this block will run
		cout<<"Member found: "<<str<<endl;
		cout<<"Name:"<<obj2.getName()<<" \tPhone:"<<obj2.getPhone()<<" \tPoints:"<<obj2.getPoints()<<endl<<endl;
	}
	else{
		cout<<"Member not found: "<<str<<endl<<endl;
	}
	
	str = "Oliver Green";
	obj2 = obj.search(str);//obj2 is an empty object as there is no member named "Oliver Green"
	if(obj2.getName()!=""){//obj2.getName() = "" as it is an empty object. So if block will not run
		cout<<"Member found: "<<str<<endl;
		cout<<"Name:"<<obj2.getName()<<" \tPhone:"<<obj2.getPhone()<<" \tPoints:"<<obj2.getPoints()<<endl<<endl;
	}
	else{	//This will run.
		cout<<"Member not found: "<<str<<endl<<endl;
	}
	
	//Display all the ClubMembers
	obj.display();
	return 0;
}
