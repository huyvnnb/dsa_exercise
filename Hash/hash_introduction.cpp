//Index Mapping
#include <iostream>
using namespace std;

#define MAX 1000

bool has[MAX+1][2];
//	[i][0]: positive
//	[i][1]: negative

void insert(int arr[], int n){
	for(int i=0; i<n; i++){
		if(arr[i] >= 0){
			has[arr[i]][0] = true;
		}
		else{
			has[abs(arr[i])][1] = true;
		}
	}
}

bool search(int key){
	if(key >= 0){
		if(has[key][0]){
			return true;
		}
		else{
			return false;
		}
	}
	key = abs(key);
	if(has[key][1]){
		return true;
	}
	return false;
}

int main(){
	int arr[] = {1,-5,33,22,-9,8,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	insert(arr, n);
	int key; cout << "Nhap: "; cin >> key;
	bool isExist = search(key);
	if(isExist){
		cout << "Exist" << endl;
	}
	else{
		cout << "Not Exist" << endl;
	}
	return 0;
}