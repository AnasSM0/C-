#include <iostream>
#include <conio.h>
using namespace std;
class tollBooth{
	
	public:
	unsigned int cars;
	double cash;
	
	
	tollBooth(){
		
		cout<<"Press any key to start the program.\n";
		
		cars=0;
		cash=0;
		
	}
	
	void payingCar(){
	
		cars++;
		cash+=0.50;
	}
	
	void noPayCar(){
	
	cars++;	
	
	}
	
	void display(){
		
		cout<<"Total Cars: "<<cars;
		cout<<endl<<"Cash Collected: $ "<<cash;
		
	}
	
};

int main(){
	
	tollBooth T1;
	
	rep:
	char choice;
	choice==getch();
	
	while (true){
		
		cout<<"\nPress P for Paying car, N for Non-paying car, or ESC to get the Total Cars and Cash: \n";
		choice=getch();
		
		if (choice == 'P' || choice == 'p'){
			T1.payingCar();
			cout<<"\nPaying Car counted.\n";
		}
		
		
		else if (choice == 'N' || choice == 'n'){
			T1.noPayCar();
			cout<<"\nNon-Paying Car counted.\n";
		}
		
		
		else if (choice == 27){
			
			cout<<endl;
			T1.display();
			break;
			
		}
	
	else {
		
		cout<<"\nInvalid character. Please try again.";
		goto rep;
		 
	}
	
		
	}
	
}
