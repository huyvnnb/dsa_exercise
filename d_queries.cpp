#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n){
	if(n<2){
		return false;
	}
	for(long long i=2; i*i<=n; i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n; cin >> n;
    for(int i=2; i<60; i++){
    	int res = pow(n, 1/i);
    	if(is_prime(res)){
    		cout << res << " " << i << endl;
    		return 0;
    	}
    }
    cout << "0" << endl;

	return 0;
}