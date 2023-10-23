#include <iostream>
#include <set>
using namespace std;

set<int> _union(int arr1[], int arr2[], int n1, int n2){
	set<int> res;
	for(int i=0; i<n1; i++){
		res.insert(arr1[i]);
	}
	for(int i=0; i<n2; i++){
		res.insert(arr2[i]);
	}
	return res;
}

set<int> _intersection(int arr1[], int arr2[], int n1, int n2){
	set<int> set1(arr1, arr1 + n1);
	set<int> set2(arr2, arr2 + n2);
}

int main(){
	int arr1[] = {7, 1, 5, 2, 3, 6};
	int arr2[] = {3, 8, 6, 20, 7};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	set<int> res = _union(arr1, arr2, n1, n2);
	set<int>::iterator it;
	for(it = res.begin(); it != res.end(); it++){
		cout << *it << " ";
	}

	cout << endl;
	return 0;
}