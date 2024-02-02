#include<iostream>
using namespace std;
template <typename T>

bool isEqualTo(T x, T y){
	
	return x==y;
	
}	

class NoEquality{
	
	int value;
	
	public:
	
	NoEquality(int val) : value(val) {}
	void Test1(){
		
		NoEquality obj1(50);
		NoEquality obj2(5);
		NoEquality obj3(80);
		
		
	}
	
};

class Equality{
	
	public: 
	
	int value;
	
	Equality(int val) : value(val) {}
	friend bool operator==(Equality lhs, Equality rhs){
		return lhs.value == rhs.value;
	}
		
};

int main(){
	
	cout<<"Comparing Fundamental Types. 1 - Equal, 0 - Not Equal";
	
	int int1=10, int2=10; 
	float float1=9.1, float2=3.14;
	char char1='A', char2='A';
	
	cout<<"\n\nUser-defined class not overloading the operator."<<endl;
	cout<<"\nInteger Comparison Result: "<<isEqualTo(int1,int2)<<endl;
	cout<<"Float Comparison Result: "<<isEqualTo(float1,float2)<<endl;
	cout<<"Character Comparison Result: "<<isEqualTo(char1,char2)<<endl;
	
	NoEquality nq(1);
	nq.Test1();
	
	Equality eq1(20);
	Equality eq2(20);
	Equality eq3(70);
	
	cout<<"\nComparing "<<eq1.value<<" and "<<eq2.value<<" with overloaded operator. Result: "<<isEqualTo(eq1, eq2)<<endl;
	cout<<"Comparing "<<eq1.value<<" and "<<eq3.value<<" with overloaded operator. Result:  "<<isEqualTo(eq1, eq3)<<endl;
	
	
}


