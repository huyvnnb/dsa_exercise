#include <bits/stdc++.h>
using namespace std;

int prec(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='*' || c=='/'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	return -1;
}

string Infix_to_Postfix(string s){
	stack<char> st;
	string res;
	int n= s.size();
	for(int i=0; i<n; i++){
		char c = s[i];
		if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
			res += c;
		}
		else if(c == '('){
			st.push(c);
		}
		else if(c == ')'){
			while(st.top() != '('){
				res += st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && prec(c) <= prec(st.top())){
				res += st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	while(!st.empty()){
		res += st.top();
		st.pop();
	}
	return res;
}

float calculate(string str){
	float res = 0;
	string s = Infix_to_Postfix(str);
	stack<float> number;
	int n = s.size();
	for(int i=0; i<n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			float num = s[i] - '0';
			number.push(num);
		}
		else{
			float num1 = number.top();
			number.pop();
			float num2 = number.top();
			number.pop();
			if(s[i] == '^'){
				res = pow(num2, num1);
			}
			else if(s[i] == '*'){
				res = num2*num1;
			}
			else if(s[i] == '/'){
				res = num2/num1;
			}
			else if(s[i] == '+'){
				res = num2 + num1;
			}
			else if(s[i] == '-'){
				res = num2 - num1;
			}
			number.push(res);
		}
	}
	return res;
}

bool isOperator(char c){
	switch(c) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return true;
	}
	return false;
}

string Postfix_to_Infix(string s){
	stack<string> st;
	string res;
	int n = s.size();
	for(int i=n-1; i>=0; i--){
		if(s[i] == ' '){
			continue;
		}
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
			st.push(string(1, s[i]));
		}
		else{
			string c1 = st.top();
			st.pop();
			string c2 = st.top();
			st.pop();
			string temp;
			temp = temp + '(' + c1 + s[i] + c2 + ')';
			st.push(temp);
		}
	}
	return st.top();
}

int main(){
	string s;
	cin >> s;
	// string str = Infix_to_Postfix(s);
	// cout << str << endl;
	s = Postfix_to_Infix(s);
	cout << s << endl;
	return 0;
}