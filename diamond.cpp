#include <iostream>
using namespace std;
class A{
	
	public:
	void display(){
		
		cout<<"A called.";
		
	}
	
};

class B: public A{
	
	public:
	void display(){
		
		cout<<"B called.";
		
	}
	
};
class C: public A{
	
	public:
	void display(){
		
		cout<<"C called.";
		
	}
	
};

class D:public B ,public C{
	
	public:
		void display(){
			
		cout<<"D called";
		
		}
		
};

int main(){
	
	D d1;
	d1.display();
	
}
