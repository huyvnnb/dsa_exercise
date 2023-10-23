#include <bits/stdc++.h>
using namespace std;

int hash_table[26];

void sortString(string &str){
	int n=str.size();
	for(int i=0; i<n; i++){
		hash_table[(str[i]-'a')]++;
	}
	int idx = 0;
	for(int i=0; i<26; i++){
			for(int k=0; k<hash_table[i]; k++){
				str[idx] = i+'a';
				idx++;
			}
	}
}

int main(){
	string s = "bbbbaaaaa";
	sortString(s);
	cout << s;
	return 0;
}