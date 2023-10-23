#include <iostream>
#define maxn 1000001
using namespace std;

int f[maxn];

int main(){
	f[0] = 1;
	int n; cin >> n;
	for(int s=1; s<=n; s++){
		for(int j=1; j<=6; j++){
			if(j<=s)
				f[s] = f[s] + f[s-j];
		}
	}
	cout << f[n];
	return 0;
}