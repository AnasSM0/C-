#include <iostream>
using namespace std;
class shape {
	
	public:
		
		virtual void draw(){
			
			cout<<"Drawing";
			
		}
	
};

class Circle:public shape{
	
	public:
	void draw(){
		
		cout<<"\nDrawing Circle.";
		
	}
	
};

class Square:public shape{
	
	public:
		
	void draw(){
		
		cout<<"\nDrawing Square.";
		
	}	
	
};

int main(){
	
	shape s1;
	s1.draw();
	
	Circle c1;
	c1.draw();
	
	Square sq1;
	sq1.draw();
	
}
