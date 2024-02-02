#include<iostream>
using namespace std;
class Shape{
	
	virtual float CalcArea()=0;
	
};

class Circle:public Shape{
	
	float radius;
	
	public:
		
		Circle(float r){
			
			radius=r;
			
		}
	
	float CalcArea(){
		
		const float Pi=3.142;
		return Pi*radius*radius;
	}
};

class Square:public Shape{
	
	float length,width;
	
	public:
		
		Square(float l,float w){
			
			length=l;
			width=w;
			
		}
	
	float CalcArea(){
		
		return length*width;
	}
};

int main(){
	
	Circle c1(3.0);
	Square s1(12.5,9);
	
	cout<<"The area of the provided circle is: "<<c1.CalcArea();
	cout<<"\nThe area of the provided square is: "<<s1.CalcArea();
}
