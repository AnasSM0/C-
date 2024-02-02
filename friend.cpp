#include<iostream>
using namespace std;
class B;
class C;

class A{
	
	int num1,num2;
	
	public: 
	
	A(){
		num1=0;
		num2=0;
		
	}
	
	friend int sum(int a, int b,B objb, C objc);
	friend class B;
	friend class C;	
};

class B{
	
	
	
	public: 
	
	int num3;
	
	B(){
		
		num3=5;
		
	}
	
	friend int sum(int a, int b, B objb);
	
	
};

class C{
	
	
	
	public: 
	
	int num4;
	
	C(int n4){
		
		num4=n4;
		
	}
	
	friend int sum(int a, int b, C objc);
	
	
};

int sum(int a, int b, B objb){
	
	return a+b+objb.num3;
	
}

int sum(int a, int b, C objc){
	
	int res=a+b+objc.num4;
	return res;
}

int sum(int a,int b, B objb, C objc){
	
	int result = a + b + objb.num3+objc.num4;
	
	return result;
	
}

int main (){
	
	A a1;
	B b1;
	C c1(10);
	
 cout<<sum(4,2,b1,c1);
	
}
