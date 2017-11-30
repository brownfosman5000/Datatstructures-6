#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


void linearsort(vector<int>,int);
void quicksort(vector<int> &,int,int);
int partition(vector<int> &,int,int);
vector<int> readNumbers(string& amofnumbers, string& properties);
void printNumbers(const vector<int>,const string amofnumbers, const string properties);
void printSorted(vector<int>,int);
void initarrs(int [],int []);
void insertionSort(vector<int>,int);
void compare();
int findIndexMatch(int , int []);


ifstream fin;
const int LINEAR = 0;
const int QUICK = 1;
const int INSERTION = 2;
const int NUMSORTS = 3;
int comparisons[3], interchanged[3];

//Keeps track of which array comps and interchange are where


int main(){

	string amofnumbers,properties;
	fin.open("data.txt");

	while(!fin.eof()){
		initarrs(comparisons,interchanged);
		vector<int> nums = readNumbers(amofnumbers,properties);
		printNumbers(nums,amofnumbers,properties);


		cout<<"LINERAR SORT---------------------------------------------------------------------------------------------------------------------"<<endl; 
		linearsort(nums,stoi(amofnumbers));
		cout<<"The linearsort made "<<comparisons[LINEAR]<<" comparisons "<<" and "<<interchanged[LINEAR]<<"swaps"<<endl<<endl;


		cout<<"INSERTION SORT---------------------------------------------------------------------------------------------------------------------"<<endl; 
		insertionSort(nums,stoi(amofnumbers));
		cout<<"The insertionSort made"<<comparisons[INSERTION]<<" comparisons"<<" and "<<interchanged[INSERTION]<<"swaps"<<endl<<endl;




		cout<<endl<<"QUICK SORT--------------------------------------------------------------------------------------------------------------"<<endl;
		quicksort(nums,0,stoi(amofnumbers));
		printSorted(nums,stoi(amofnumbers));
		cout<<endl<<"The quicksort made "<<comparisons[QUICK]<<" comparisons "<<" and "<<interchanged[QUICK]<<"swaps"<<endl<<endl;
		
		compare();
		cout<<endl<<endl<<endl;
	}


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

	for(int i = 0;i<amofnumbers;i++){
		smallest = i;
		for(int j = i+1;j<amofnumbers;j++){
			comparisons[LINEAR]++;
			if(nums[smallest] > nums[j]){
				interchanged[LINEAR]++;
				smallest = j;
			}
		}
		
		swap(nums[smallest],nums[i]);

	}
	printSorted(nums,amofnumbers);
	cout<<endl;
}


int partition (vector<int> &arr, int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        comparisons[QUICK]++;
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            interchanged[QUICK]++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


void insertionSort(vector<int>nums,int amofnumbers){
	int j = 0;
	for(int i = 1;i<amofnumbers;i++){
		j=i;
		while(j != 0){
			comparisons[INSERTION]++;
			if(nums[j] < nums[j-1]){
				interchanged[INSERTION]++;
				swap(nums[j],nums[j-1]);
			}

			j--;	
		}

	}
	printSorted(nums,amofnumbers);
	cout<<endl;

}

void compare(){
	//Find smallest next smallest...

	int smallest, index_for_string = 0;
	vector<int> copy (comparisons, comparisons+sizeof(comparisons)/sizeof(comparisons[0]));
	vector<int> copyinter (interchanged, interchanged+sizeof(interchanged)/sizeof(interchanged[0]));

	string sort_names[] = {"Linear","Quick","Insertion"};


	//sort values 
	sort(copy.begin(),copy.end());
	sort(copyinter.begin(),copyinter.end());


	//Pick from the start of the vector and print the name of sort 
	index_for_string = findIndexMatch(copy[0],comparisons);
	cout<<"Smallest amount of comparisons: "<<sort_names[index_for_string]<<endl;

	index_for_string = findIndexMatch(copy[1],comparisons);
	cout<<"Middle amount of comparisons:: "<<sort_names[index_for_string]<<endl;

	index_for_string = findIndexMatch(copy[2],comparisons);
	cout<<"Largest amount of comparisons:: "<<sort_names[index_for_string]<<endl; 


	//Pick from the start of the vector and print the name of sort 
	index_for_string = findIndexMatch(copyinter[0],interchanged);
	cout<<"Smallest amount of swapped: "<<sort_names[index_for_string]<<endl;

	index_for_string = findIndexMatch(copyinter[1],interchanged);
	cout<<"Middle amount of swapped: "<<sort_names[index_for_string]<<endl;

	index_for_string = findIndexMatch(copyinter[2],interchanged);
	cout<<"Largest amount swapped: "<<sort_names[index_for_string]<<endl; 
}


//Find index for the value
int findIndexMatch(int value_to_be_found, int comparisons[]){
	for(int i = 0;i<3;i++)
		if(comparisons[i] == value_to_be_found) return i;

}










