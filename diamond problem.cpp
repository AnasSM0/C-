#include<iostream>
using namespace std;
class A{
	protected:
	int a=5;
	public:
	A(){
		
		cout<<a;
	}
	
};

class B: virtual public A{
	
	public:
	B():A(){
		
	
		
	}
	
};

class C:virtual public A{
	
	public:
	C():A(){
		
	
	}
	
};

class D:public B,public C{
	
	public:
	D( ):A(),B(),C(){
		
	
	}
	
};

int main(){
	A a1;
	B b1;
	C c1;
	D d1;
	
}
