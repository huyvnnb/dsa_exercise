#include <bits/stdc++.h>
using namespace std;

void computePSArray(string pat, int m, int lps[]){
	int len = 0;
	lps[0] = 0;
	int i=1;
	while(i<m){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len!=0){
				len = lps[len-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPsearch(string txt, string pat){
	int n = txt.size();
	int m = pat.size();
	int lps[m];
	computePSArray(pat, m, lps);

	int i=0;
	int j=0;
	bool found = false;
	while(i<n){	
		if(txt[i]==pat[j]){
			i++;
			j++;
		}
		if(j==m){
			cout << "Find " << pat << " at index " << i-j << endl;
			found = true;
			j = lps[j-1];
		}
		else if(txt[i]!=pat[j]){
			if(j!=0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
	}
	if(!found){
		cout << "Not exist in text" << endl;
	}
}

int main() {
	string txt = "Nguyen Quang Huy";
	string pat = "en";
	KMPsearch(txt, pat);
    return 0;
}