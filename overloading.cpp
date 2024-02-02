#include <iostream>
using namespace std;
class op{
	
	int A;
	int B;
	
	public: 
	
	op(int a, int b){
		
		A = a;
		B = b;
		
		
	}
	
	void operator -(int value){
		
		int c = A + value;
		cout<<c;
		
	 	c*=c;
	 	cout<<"\n\nUpdated c "<<c;
		
	}
	
	
};

int main (){
	
	op obj1(5,0);
	
	 obj1 - 5;
	
}
