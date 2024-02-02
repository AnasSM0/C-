#include<iostream>
using namespace std;
class ObMarks{
	
	virtual float getPerc()=0;
	
};

class Ali:public ObMarks{
	
	float oopLabMarks,oopTheoryMarks;
	
	public:
		Ali(float oopLab,float oopTheory){
			
			oopLabMarks=oopLab;
			oopTheoryMarks=oopTheory;
			
		}
		
		float getPerc(){
			int Tmarks=200;
			float obtMarks=oopLabMarks+oopTheoryMarks;
			return (obtMarks/Tmarks)*100;
		}
	
};

class Ahmed:public ObMarks{
	
	float sub1Marks,sub2Marks,sub3Marks,sub4Marks;
	
	public:
		Ahmed(float sub1, float sub2, float sub3, float sub4){
			
			sub1Marks=sub1;
			sub2Marks=sub2;
			sub3Marks=sub3;
			sub4Marks=sub4;
			
		}
	
	float getPerc(){
		
		int Tmarks=400;
		float obtMarks=sub1Marks+sub2Marks+sub3Marks+sub4Marks;
		return (obtMarks/Tmarks)*100;
		
	}
};

int main(){
	
	Ali a1(75.5,82);
	Ahmed a2(95,83.75,88,71);
	
	cout<<"Ali's Percentage: "<<a1.getPerc();
	cout<<"\nAhmed's Percentage: "<<a2.getPerc();
	
}
