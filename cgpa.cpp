#include <iostream>
using namespace std;
class gpa{
	
	int totalchours,chours,courses;
	double totalgrades,grade,cgpa;
	
		Student(){
			totalchours=0;
			totalgrades=0;
		}
		
	public:
		void get(){
			
			cout<<"Enter the total number of courses: ";
			cin>>courses;
			
			cout<<"Enter the total number of credit hours: ";
			cin>>totalchours;
			
			for (int i=0;i<courses;i++){
				cout<<"\nEnter the grade for course"<<(i + 1)<<": ";
				cin>>grade;
				
				cout<<"Enter the credit hours for course"<<(i + 1)<<": ";
				cin>>chours;
				
				totalgrades+=grade*chours;
				
			}	
			
		}
		
		void calculate(){
			cgpa=totalgrades/totalchours;
			cout<<"\nYour total CGPA is "<<cgpa<<endl;
			
			if(cgpa>=3.0 && chours>=26){
				
				cout<<"\nYou are elgible for thesis.";
				
			}
			
			else{
				
				cout<<"\nYou are not elgible for thesis.";
				
			}
		}
		
};

int main(){
	
	gpa s1;
	s1.get();
	s1.calculate();
	
}
