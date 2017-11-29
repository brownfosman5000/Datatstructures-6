#include <iostream>

using namespace std;

int main(){
	int amofnumbers = 0,range;
	cout<<"How many numbers: ";
	cin>>amofnumbers;
	cout<<"What range would you like these numbers to fall in: ";
	cin>>range;
	cout<<endl;
	for(int i = 0;i<amofnumbers;i++){
		cout<<", "<<rand() % range;	
	}
	cout<<endl;
}
