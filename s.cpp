#include <iostream>
using namespace std;
void linearsort(int[]);
void quicksort(int [],int,int);
//void swap(int &,int &);
int divide(int nums[],int lo,int high);
int main(){
	int nums[] = {7,6,5,4,3,2,1,0};
	// for(int i =0;i<6;i++){
	// 	cout<<nums[i]<<endl;
	// }
	// linearsort(nums);
	// cout<<endl;
	// for(int i =0;i<6;i++){
	// 	cout<<nums[i]<<endl;
	// }
	//linearsort(nums);
	//swap(nums[1],nums[0]);
	for(int i =0;i<8;i++){
		cout<<nums[i]<<"    ";
	}
	cout<<endl;
	//divide(nums,0,6);
	//ivide(nums,0,6);
	quicksort(nums,0,8);
	for(int i =0;i<8;i++){
		cout<<nums[i]<<"    ";
	}
	// for(int i =0;i<6;i++){
	// 	cout<<nums[i]<<"    ";
	// }
		
}

void linearsort(int nums[]){
	int smallest,temp;

	for(int i = 0;i<8;i++){
		smallest = i;
		for(int j = i+1;j<8;j++){
			if(nums[smallest] > nums[j]){
				smallest = j;
			}
		}
		
		temp = nums[smallest];
		nums[smallest] = nums[i];
		nums[i] = temp;
	}
}

void quicksort(int nums[],int start,int end){

	if(start < end ){
		int wall = divide(nums,start,end);
		//Less than piv
		quicksort(nums,start,wall-1);
		//Greater than piv
		quicksort(nums,wall+1,end);
		
	}
}

int divide(int nums[],int lo,int high){
	int pivot = nums[lo];
	//cout<<"Pivot"<<nums[high];
	int index = lo;
	for(int i = lo;i<high;i++){
		if(nums[i] <= pivot){
			swap(nums[i],nums[index]);
			cout<<"swapped";
			index++;
		}
	}
		for(int i =0;i<8;i++){
		cout<<nums[i]<<"    ";
	}
	cout<<endl;

	swap(nums[index],nums[high]);
	
	return index;

}










