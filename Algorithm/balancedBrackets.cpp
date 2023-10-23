#include <bits/stdc++.h>
using namespace std;

bool check(string s){
	stack<char> st;
	int n = s.size();
	for(int i=0; i<n; i++){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
			st.push(s[i]);
		}
		else{
			if(st.empty()){
				return false;
			}
			if((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{')){
				st.pop();
			}
			else{
				return false;
			}
		}
	}
	if(st.empty()){
		return true;
	}
	return false;
}

bool check2(string s){
	int i = -1;
	for(char c:s){
		if(c == '(' || c == '[' || c== '{'){
			s[++i] = c;
		}
		else{
			if(i>=0 && ((c==')' && s[i] == '(') || (c==']' && s[i] == '[') || (c=='}' && s[i] == '{'))){
				i--;
			}
			else{
				return false;
			}
		}
	}
	return i==-1;
}

int main(){
	string bracket;
	cin >> bracket;
	if(check2(bracket)){
		cout << "Balanced" << endl;
	}
	else{
		cout << "Not Balanced" << endl;
	}
	return 0;
}