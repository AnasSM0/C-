#include <iostream>
using namespace std; 

int num,choice;
float num1;
char ch;
	
class encrypt{
	
	public:
	 
	
	
	encrypt(){
	
	cout<<"To begin encryption, select a format.\n\nEnter 1 for integer\nEnter 2 for float\nEnter 3 for character\n\nEnter your choice: ";
	cin>>choice;
	
	switch (choice){
	
	case 1:
	
	if (choice == 1){
		
		cout<<"\nEnter any integer: ";
		cin>>num;
	}	
		
		
	case 2:
	
	if (choice == 2){
		
		cout<<"\nEnter any float: ";
		cin>>num1;
	}	


	case 3:
	
	if (choice == 3){
		
		cout<<"\nEnter any character: ";
		cin>>ch;
	}	
	
	}
	
}	

void encNum(){
	num+=5;
	cout<<"\nYour encrypted number is "<<num;
}


void encFloat(){
	num1+=5;
	cout<<"\nYour encrypted float is "<<num1;
}


void encChar(){
	ch+=5;
	cout<<"\nYour encrypted Character is "<<ch;
}

};

int main(){
	
	encrypt e1;
	if (choice == 1 ){
	e1.encNum();
}
	if (choice == 2){
	e1.encFloat();
}

	if (choice == 3){
	e1.encChar();
}
	
	
}

