#include<iostream>
using namespace std;
class num{
	
	int a;
	
	public:
	num(){
		a=0;
	}
	
	num(int num){
		a=num;
		cout<<num<<endl;
	}
	
	num(num &obj){
		
		cout<<"Copy constructor called."<<endl;
		a=obj.a;
		cout<<obj.a;
		
	}
	
};

int main(){
	
	num a(1),b(22),c(45);
	num d(b);
	
	
}
