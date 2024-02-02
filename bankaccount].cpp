#include<iostream>
using namespace std;
class bank {
	
	public:
		
	long int accno, accbal,amount;
	std::string depname;
	char acctype;
	
	void set(){
	cout<<"Enter your account number: ";
	cin>>accno;
	
	cout<<"Enter depositor name: ";
	cin>>depname;
	
	cout<<"Enter account type; Current (C) , Savings (S) , Default (D) : ";
	cin>>acctype;
	
	cout<<"Enter your balance: ";
	cin>>accbal;
	
}
	
	void deposit(){
	
	if(amount>=100){
	
	cout<<endl<<"Enter amount to deposit: ";
	cin>>amount;
	
	accbal+=amount;
	
}

else{
	cout<<"You have entered an insufficient amount."<<endl;
}
		
}

	void withdraw(){
	
	if(amount>=100){
	
	cout<<"\nEnter amount to withdraw: ";
	cin>>amount;
	
	accbal-=amount;
	
}

else {
	cout<<"You have entered an insufficient amount.";
}
	

	
}

void showbal(){
	
	cout<<"\nAccount name: "<<depname<<"\nCurrent Balance: "<<accbal;
	
	
}

};

int main(){
	
	bank acc1;
	
	acc1.set();
	acc1.deposit();	
	acc1.withdraw();
	acc1.showbal();
	
}
