#include <bits/stdc++.h>
using namespace std;

long long fib[93];


void gen(){
	fib[0] = 1;
	fib[1] = 1;
	for(int i=2;i<93; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
}

int solve(long long n){
	long long temp = n;
	//int product[93];
	int i=2;
	int cnt = 0;
	while(n >= fib[i]){
		//int j = i;
		temp = n;
		int j = i;
		while(temp > 1){
			//int j = i;
			while(temp % fib[j] != 0){
				if(temp < fib[j]){
					//i++;
					break;
				}
				else{
					j++;
				}
			}
			while(temp % fib[j] == 0){
				//long long prev = temp;
				temp /= fib[j];
				if(temp < fib[j]){
					//i++;
					break;
				}
			}
		}
		if(temp == 1){
			cnt++;
		}
		i++;
	}
	return cnt;
}

int main(){
	gen();
	int t; cin >> t;
	while(t--){
		long long n; 
		cin>> n;
		cout << solve(n) << endl;
	return 0;
	}
}