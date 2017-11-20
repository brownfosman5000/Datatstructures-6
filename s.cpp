#include <iostream>
using namespace std;

void linearsort(int []);
int main(){
	int nums[6];

	nums[0] = 5;
	nums[1] = 3;
	nums[2] = 7;
	nums[3] = 1;
	nums[4] = 9;
	nums[5] = 8;
	for(int i =0;i<6;i++){
		cout<<nums[i]<<endl;
	}
	linearsort(nums);
	cout<<endl;
	for(int i =0;i<6;i++){
		cout<<nums[i]<<endl;
	}
}

void linearsort(int nums[]){
	int smallest = 0,temp;
	for(int i = 0;i<6;i++){
		smallest = i;
		for(int j = i+1;j<6;j++){
			
			if(nums[smallest] > nums[j]){
				smallest = j;
			}
		}
		
		temp = nums[smallest];
		nums[smallest] = nums[i];
		nums[i] = temp;
	}
}