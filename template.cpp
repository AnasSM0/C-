#include <iostream>
using namespace std;
template <typename T> 
T findmin(T n1, T n2){
	
	if(n1<n2){
		
		return n1;
		
	}
	
	else {
		
		return n2;
		
	}
}

int main(){
	
	cout<<findmin<int>(4,6)<<endl;
	cout<<findmin<double>(5.9,6.9)<<endl;
	cout<<findmin<char>(98,101)<<endl;
}
