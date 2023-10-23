#include <bits/stdc++.h>
using namespace std;


int main(){
	int n, q;
cin >> n >> q;
vector<int> arr(n+1);
vector<int> diff(n+2);
for(int i=1; i<=n; i++){
    cin >> arr[i];
    diff[i] = arr[i] - arr[i-1];
}
while(q--){
    int k, o1, o2;
    cin >> k >> o1 >> o2;
    if(k==1){
        int diff_value = o2 - arr[o1];
        arr[o1] = o2;
        diff[o1] += diff_value;
        diff[o1+1] -= diff_value;
    }
    else if(k==2){
        long sum = 0;
        for(int i=1; i<=o2; i++){
            sum += diff[i];
        }
        cout << sum << endl;
    }
}
	// int n, q;
	// cin >> n >> q;
	// vector<int> arr(n+1);
	// vector<long> prefix_sum(n+1);
	// prefix_sum[0] = 0;
	// for(int i=1; i<=n; i++){
	// 	cin >> arr[i];
	// 	prefix_sum[i] = prefix_sum[i-1] + arr[i];
	// }
	// while(q--){
	// 	int k, o1, o2;
	// 	cin >> k >> o1 >> o2;
	// 	if(k==1){
	// 		long diff = o2 - arr[o1];
	// 		arr[o1] = o2;
	// 		for(int i=o1; i<=n; i++){
	// 			prefix_sum[i] += diff;
	// 		}
	// 	}
	// 	else if(k==2){
	// 		cout << prefix_sum[o2] - prefix_sum[o1-1] << endl;
	// 	}
	// }

	
	return 0;
}
