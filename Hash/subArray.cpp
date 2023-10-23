#include <bits/stdc++.h>
using namespace std;

//Method 1
//Naive way

bool isSubset(int mainArr[], int subArr[], int main, int sub){
	int i, j;
	for(i=0; i<sub; i++){
		for(j=0; j<main; j++){
			if(mainArr[j] == subArr[i]){
				break;
			}
		}
		if(j==main){
			return false;
		}
	}
	return true;
}

//Method 2
//Using quicksort for main array

int partition(int arr[], int left, int right){
	int pivot = arr[right];
	int i = left - 1;
	int j;
	for(j=left; j<=right-1; j++){
		if(arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[right]);
	return (i+1);
}

void quickSort(int arr[], int left, int right){
	if(left<right){
		int pi = partition(arr, left, right);
		quickSort(arr,left,pi-1);
		quickSort(arr,pi+1, right);
	}
}

bool binarySearch(int arr[], int low, int high, int key){
	while(high >= low){
		int mid = (low + high)/2;
		if(arr[mid] == key){
			return true;
		}
		if(arr[mid] < key){
			low = mid + 1;
		}
		if(arr[mid] > key){
			high = mid - 1;
		}
	}
	return false;
}

bool isSubset2(int mainArr[], int subArr[], int main, int sub){
	quickSort(mainArr, 0, main - 1);
	for(int i=0; i< sub; i++){
		if(binarySearch(mainArr, 0, main-1, subArr[i]) == false){
			return false;
		}
	}
	return true;
}

bool isSubset3(int mainArr[], int subArr[], int main, int sub){
	if(main < sub){
		return false;
	}
	quickSort(mainArr, 0, main - 1);
	quickSort(subArr, 0, sub - 1);
	int i=0, j=0;
	while(i<main && j<sub){
		if(mainArr[i] < subArr[j]){
			i++;
		}
		else if(mainArr[i] == subArr[j]){
			i++;
			j++;
		}
		else if(mainArr[i] > subArr[j]){
			return false;
		}
	}
	return (j<sub) ? false : true;
}

//Print function
void print(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int mainArr[] = {11, 1, 13, 21, 3, 7};
	int subArr[] = {11, 3, 7, 1};
	int main = sizeof(mainArr)/sizeof(mainArr[0]);
	int sub = sizeof(subArr)/sizeof(subArr[0]);
	bool check = isSubset3(mainArr, subArr, main, sub);
	//cout << binarySearch(mainArr, 0, main-1, 11);

	// quickSort(mainArr, 0, main-1);
	// print(mainArr, main);
	if(check){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}