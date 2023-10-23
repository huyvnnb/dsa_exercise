#include <iostream>
using namespace std;

void rotate1(int arr[], int n, int d){
    while(d){
        int last = arr[0];
        for(int i=0; i<n-1; i++){
            arr[i] = arr[i+1];
        }
        arr[n-1] = last;
        d--;
    }
}

void rotate2(int arr[], int n, int d){
    int temp[n];
    int index=0;
    for(int i=d; i<n; i++){
        temp[index++] = arr[i];
    }
    for(int i=0; i<d; i++){
        temp[index++] = arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
 
    else
        return gcd(b, a % b);
}

void rotate3(int arr[], int n, int d)
{
    /* To handle if d >= n */
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;
 
        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;
            
            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
 
void reverse(int arr[], int l, int r){
    int mid = l + (r-l)/2;
    for(int i=l; i<=mid; i++){
        int temp = arr[i];
        arr[i] = arr[r+l-i];
        arr[r+l-i] = temp; 
    }
} 
void rotate4(int arr[], int n, int d){
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6,7,8,9,10 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;
    rotate4(arr,n,d);
    printArray(arr, n);
    return n;
}