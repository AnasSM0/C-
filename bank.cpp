#include <iostream>
using namespace std;
class MAJUBank{
	
	public:
		
		virtual int getBal()=0;
	
};

class ABL: public MAJUBank{
	
	public:
		
		int getBal(){
			
		return 10000;
			
		}
	
};


class DIB: public MAJUBank{
	
	public:
		
		int getBal(){
			
		return 15000;
			
		}
	
};


class HBL: public MAJUBank{
	
	public:
		
		int getBal(){
			
		return 20000;
			
		}
	
};

int main(){
	
	ABL acc1;
	DIB acc2;
	HBL acc3;
	
	cout<<"The current balance in ABL is: "<<acc1.getBal();
	cout<<"\nThe current balance in DIB is: "<<acc2.getBal();
	cout<<"\nThe current balance in HBL is: "<<acc3.getBal();
	
	
}
