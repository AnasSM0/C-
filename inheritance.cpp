#include <iostream>
using namespace std;

const int MaxAuthors=10;
const int MaxBooks=10;
const int MaxEmail=10;
int array;

class Documents{

protected:	

string author[MaxAuthors];
string date[MaxAuthors];


public:
void getArray(){

cout<<"Enter the number of authors you want to add: ";
cin>>array;

}

void addAuthor(){

for (int i=0;i<array;i++){

cout<<"\nEnter the name of author "<<i+1<<": ";
cin.ignore();
getline(cin, author[i]);


cout<<"\nEnter the date of creation: ";
cin>>date[i];

}

}

void displayAuthors(){

cout<<"\nAuthor Info: \n";

for (int i=0;i<array;i++){

cout<<"\nAuthor "<<i+1<<" :"<<"\nAuthor Name: "<<author[i]<<"\nDate Published: "<<date[i]<<endl;

}

}

};

class Book: public Documents{

string Title[MaxBooks];
int Edition[MaxBooks];

public:
void AddBook(){

for(int i=0;i<array;i++){

cout<<"Enter the title of Book "<<i+1<<": ";
cin.ignore();
getline(cin, Title[i]);

cout<<"\nEnter Edition of the book: ";
cin>>Edition[i];

cout<<endl;

}

}

void displayBooks(){

cout<<"Book Info: \n";

for(int i=0;i<array;i++){

cout<<"\nBook "<<i+1<<":"<<"\nBook Name: "<<Title[i]<<"\nEdition of Book: "<<Edition[i]<<endl;

}
}

};

class Email: public Book{

string subMail[MaxEmail];
string Rname[MaxEmail];
int recipients;

public:
Email(){
	
cout<<"Please Enter the number of Email recipients: ";
cin>>recipients;
	
}

public:

void AddEmail(){
	
for (int i=0;i<recipients;i++){
		
cout<<"\nEnter Email "<<i+1<<": ";;
cin>>subMail[i];
		
cout<<"\nEnter the name of Recipient: ";
cin.ignore();
getline(cin, Rname[i]);

}

cout<<endl;	

}
	
void displayEmail(){
		
	cout<<"Email Info: \n";
		
	for (int i=0;i<recipients;i++){
			
	cout<<"\nEmail "<<i+1<<":"<<"\nEmail: "<<subMail[i]<<"\Recipient: "<<Rname[i]<<endl;
			
}
		
}
	

};

int main(){

Documents d1;
d1.getArray();
d1.addAuthor();
d1.displayAuthors();

cout<<"------------------------------------------------------------------------------------------------------------------------\n\n";

Book b1;
b1.AddBook();
b1.displayBooks();

cout<<"\n------------------------------------------------------------------------------------------------------------------------\n\n";

Email e1;
e1.AddEmail();
e1.displayEmail();

}

