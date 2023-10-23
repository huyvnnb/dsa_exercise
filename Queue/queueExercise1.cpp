//Install stack using queue
#include <iostream>
#include <queue>
using namespace std;

struct Stack{
	queue<int> q1, q2;

	void push(int x){
		q2.push(x);
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop(){
		if(q1.empty()){
			return;
		}
		q1.pop();
	}

	int size(){
		return q1.size();
	}
};

int main(){
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << "Size is " << s.size() << endl;
	s.pop();
	s.pop();
	s.pop();
	cout << "Size is " << s.size() << endl;
	return 0;
}