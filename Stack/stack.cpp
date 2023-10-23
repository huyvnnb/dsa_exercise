#include <iostream>
using namespace std;

#define MAX 1000
int stack[1000];
int n=-1;

void push(int x){
	if(n>=1000){
		cout << "Stack Overflow" << endl;
		return;
	}
	stack[++n] = x;
}
void pop(){
	if(n<0){
		cout << "Stack Underflow" << endl;
		return;
	}
	n--;
}

int top(){
	if(n>=0){
		return stack[n];
	}
	return 0;
}

bool isEmpty(){
	if(n<0){
		return 1;
	}
	return 0;
}

int main(){
	push(5);
	push(10);
	push(20);
	push(30);
	while(!isEmpty()){
		cout << top() << " ";
		pop();	
	}
	cout << endl;
	return 0;
}