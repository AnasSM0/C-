#include <iostream>
using namespace std;
class animal {
	
	static int count;
	static int animalId;
	string animalName;
	
	public:
		
		void setId( int id){
			
			animalId=id;
			count++;
		}
		
		int getId(){
			
			return animalId;
			
		}
	
		void setname(string name){
			
			animalName=name;
			
		}
		
		string getname(){
			
			return animalName;
			
		}
		
		void display(){
					
			cout<<"The animal name is "<<animalName<<endl;
			cout<<"The animal id of animal #"<<count<< " is "<<animalId<<endl;
			
		}
		
		static int displaycount(){
			
			cout<<"The value of count is "<<count<<endl;
			
		}
		
		static int displayid(){
			
			cout<<"\n\n\nID: "<<animalId<<endl;
			
		}
};

int animal::count;
int animal::animalId;

int main(){
	
	animal a1,a2;
	
	a1.setId(1001);
	a1.getId();
	a1.setname("lion");
	a1.getname();
	a1.display();
	a1.displaycount();
	
	cout<<endl;
	
	a2.setId(1002);
	a2.getId();
	a2.setname("shark");
	a2.getname();
	a2.display();
	a2.displaycount();	
	a2.displayid();
	
	
	
	
}
