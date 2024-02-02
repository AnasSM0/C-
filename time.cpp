#include <iostream>
using namespace std;
class time{
	
	public:
	int hours,mins,secs;
	
	time() {
	hours=0;
	mins=0;
	secs=0;
	}
	
	time(int h, int m, int s){
		
		hours=h;
		mins=m;
		secs=s;
		

	
	}
	
	void display(){
		
		cout<<hours<<" : "<<mins<<" : "<<secs;
		
	}
	
	
	time sumTime(const time& t1, const time& t2){
		
		time res;
		
		res.secs=t1.secs + t2.secs;
		res.mins=t1.mins + t2.mins + (res.secs / 60);
		res.secs%=60;
		res.hours=t1.hours + t2.hours + (res.mins/60);
		res.mins%=60;
		
		return res;
		
	}
	
};

int main() {
	
	time t1(1,30,2);
	cout<<"Time 1 -  ";
	t1.display();	
	
	time t2(11,50,23);
	cout<<"\nTime 2 -  ";
	t2.display();
	
	time t3;
	t3=t3.sumTime(t1,t2);
	cout<<"\nResultant Time -  ";
	t3.display();	
	
	
}
