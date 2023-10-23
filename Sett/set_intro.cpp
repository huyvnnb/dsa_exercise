#include <iostream>
#include <set>
#include <unordered_set>
#include <limits.h>
using namespace std;

void printDuplicates(int arr[], int n){
	unordered_set<int> intSet;
	unordered_set<int> duplicate;
	for(int i=0; i<n; i++){
		if(intSet.find(arr[i]) == intSet.end()){
			intSet.insert(arr[i]);
		}
		else{
			duplicate.insert(arr[i]);
		}
	}
	unordered_set<int>::iterator it;
	for(it = duplicate.begin(); it != duplicate.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

int main(){
	int arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printDuplicates(arr, n);
	multiset<int> mset;
	cout << mset.max_size() << " " << INT_MAX << endl;
	return 0;
}