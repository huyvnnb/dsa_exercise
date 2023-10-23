#include <bits/stdc++.h>
using namespace std;

int arr[93];


long long fibo(int n){
	arr[0] = 0;
	arr[1] = 1;
	if(n>1 && arr[n] == 0){
		arr[n] = fibo(n-1) + fibo(n-2);
	}
	return arr[n];
}

int lcs(string s1, string s2, int m, int n){
	if(m==0 || n==0){
		return 0;
	}
	else if(s1[m-1] == s2[n-1]){
		return 1+lcs(s1,s2,m-1, n-1);
	}
	else{
		return max(lcs(s1, s2, m, n-1), lcs(s1, s2, m-1, n));
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s1 = "ABCD";
	string s2 = "ABD";
	cout << lcs(s1, s2, s1.size(), s2.size());
	return 0;
}