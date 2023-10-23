#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition1(int arr[], int low, int high){
	int pivot = arr[high];
	int left = low;
	int right = high-1;
	while(left<=right){
		while(arr[left] < pivot){
			left++;
		}
		while(arr[right] > pivot){
			right--;
		}
		if(left <= right){
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	swap(arr[left], arr[high]);
	return left;
}
int partition2(int arr[], int low, int high){
	int pivot = arr[low];
	int i = low+1;
	for(int j=low+1; j<=high; j++){
		if(arr[j] < pivot){
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i-1], arr[low]);
	return i-1;
}

void quickSort(int arr[], int low, int high){
	if(low<high){
		int pi = partition2(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
	
}

void print(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
}

int main(){
	int arr[] = {42,23,41,9,12,84,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	print(arr,n);
	cout << endl;
	quickSort(arr,0,n-1);
	print(arr,n);

	return 0;
}