#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void linearsort(vector<int>,int);
void quicksort(vector<int>,int,int);
int divide(vector<int>,int lo,int high);
vector<int> readNumbers(string& amofnumbers, string& properties);
void printNumbers(const vector<int>,const string amofnumbers, const string properties);
void printSorted(vector<int>,int);
void initarrs(int [],int []);
void countSort(vector<intt>, int, int);
void radixsort(vector<int> , int );

ifstream fin;
int comparisons[3], interchanged[3];
//Keeps track of which array comps and interchange are where
const int LINEAR = 0;
const int QUICK = 1;
const int RADIX = 2;


int main(){

	string amofnumbers,properties;
	fin.open("data.txt");

	while(!fin.eof()){
		initarrs(comparisons,interchanged);
		vector<int> nums = readNumbers(amofnumbers,properties);
		printNumbers(nums,amofnumbers,properties);
		cout<<"LINERAR SORT---------------------------------------------------------------------------------------------------------------------"<<endl; 
		linearsort(nums,stoi(amofnumbers));
		cout<<"The linearsort made "<<comparisons[LINEAR]<<"comparisons"<<" and "<<interchanged[LINEAR]<<"swaps"<<endl;
		

		radixsort(nums,stoi(amofnumbers))
		cout<<"The radixsort made"<<comparisons[RADIX]<<"comparisons"<<"and "<<interchanged[RADIX]<<"swaps"<<endl;
		printSorted(nums,stoi(amofnumbers));



		cout<<endl<<"QUICK SORT--------------------------------------------------------------------------------------------------------------"<<endl;
		quicksort(nums,0,stoi(amofnumbers));
		cout<<"The quicksort made "<<comparisons[QUICK]<<"comparisons"<<" and "<<interchanged[QUICK]<<"swaps"<<endl;
		printSorted(nums,stoi(amofnumbers));
		

		cout<<endl<<endl<<endl;
	}
	//printNumbers(nums);


	// linearsort(nums);
	// for(int i =0;i<8;i++){
	// 	cout<<nums[i]<<"    ";
	// }
	// cout<<endl;



	//quicksort(nums,0,8);

}
void initarrs(int comparisons[],int interchanged[]){
	for(int i = 0;i<3;i++){
		comparisons[i] = 0;
		interchanged[i] = 0;
	}
}

vector<int> readNumbers(string& amofnumbers, string& properties){
	string num;
	fin>>amofnumbers;

	vector<int> nums;
	getline(fin,properties);

	for(int i = 0;i<stoi(amofnumbers);i++){
		fin>>num;
		nums.push_back(stoi(num));
	}

	return nums;
}

void printNumbers(const vector<int> nums,const string amofnumbers,const string properties) {
	cout<<amofnumbers<<properties<<endl;
	for(int i =0;i<stoi(amofnumbers);i++){
		cout<<nums[i]<<"   ";
	}
	cout<<endl;
}

void printSorted(vector<int> nums,int amofnumbers){
	cout<<"SORTED: ";
	for(int i = 0;i<amofnumbers;i++){
		cout<<nums[i]<<"    ";
	}
}


void linearsort(vector<int> nums,int amofnumbers){
	int smallest,temp;

	for(int i = 0;i<8;i++){
		smallest = i;
		for(int j = i+1;j<amofnumbers;j++){
			comparisons[LINEAR]++;
			if(nums[smallest] > nums[j]){
				interchanged[LINEAR]++;
				smallest = j;
			}
		}
		
		temp = nums[smallest];
		nums[smallest] = nums[i];
		nums[i] = temp;
	}
	printSorted(nums,amofnumbers);
	cout<<endl;
}

void quicksort(vector<int>nums,int start,int end){

	if(start < end ){
		int wall = divide(nums,start,end);
		//Less than piv
		quicksort(nums,start,wall-1);
		//Greater than piv
		quicksort(nums,wall+1,end);
		
	}
}

int divide(vector<int>nums,int lo,int high){
	int pivot = nums[lo];
	//cout<<"Pivot"<<nums[high];
	int index = lo;
	for(int i = lo;i<high;i++){
		comparisons[QUICK]++;
		if(nums[i] <= pivot){
			interchanged[QUICK]++;
			swap(nums[i],nums[index]);
			index++;
		}
	}
	swap(nums[index],nums[high]);
	
	return index;

}



 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(vector<intt> v;, int n, int exp){
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using 
// Radix Sort
void radixsort(vector<int> arr, int n){
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}








