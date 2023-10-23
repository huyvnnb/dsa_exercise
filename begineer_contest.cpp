#include <bits/stdc++.h>
using namespace std;

void string_solve(string s1, string s2, int l, int r, int u, int v){
	string substr1 = s1.substr(l, r-l+1);
	string substr2 = s2.substr(u, v-u+1);
	if(substr1>substr2){
		cout << ">";
	}
	else if(substr1==substr2){
		cout << "=";
	}
	else{
		cout << "<";
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string sn = "x", sm = "x";
    for(int i=1; i<=2; i++){
    	string str;
    	cin >> str;
    	if(i==1){
    		sn += str;
    	}
    	if(i==2){
    		sm += str;
    	}
    }
    int q; cin >> q;
    while(q--){
    	int l, r, u, v; 
    	cin >> l >> r >> u >> v;
    	string_solve(sn, sm, l, r, u, v);
    }
    return 0;
}
