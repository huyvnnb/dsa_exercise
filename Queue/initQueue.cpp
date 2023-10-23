#include <iostream>
#include <limits.h>
using namespace std;

// struct qnode{
// 	int data;
// 	qnode *next;
// 	qnode(int x){
// 		data = x;
// 		next = NULL;
// 	}
// };

// struct Queue{
// 	qnode *front, *rear;
// 	Queue(){
// 		front = rear = NULL;
// 	}

// 	void enqueue(int data){
// 		qnode *new_node = new qnode(data);
// 		if(rear==NULL){
// 			rear = front = new_node;
// 			return;
// 		}
// 		rear->next = new_node;
// 		rear = new_node;
// 	}

// 	void dequeue(){
// 		if(front == NULL){
// 			return;
// 		}
// 		qnode *temp = front;
// 		front = front->next;
// 		if(front == NULL){
// 			rear = NULL;
// 		}
// 		delete temp;
// 	}

// 	bool isEmpty(){
// 		return front == NULL;
// 	}

// 	int head(){
// 		if(front == NULL){
// 			return INT_MIN;
// 		}
// 		return front->data;
// 	}
// };

struct Queue{
	int front, rear, capacity;
	int *queue;
	Queue(int c){
		front = rear = 0;
		capacity = c;
		queue = new int[capacity];
	}

	~Queue(){
		delete[] queue;
	}

	void enqueue(int x){
		if(capacity == rear){
			cout << "Queue is full" << endl;
			return;
		}
		queue[rear] = x;
		rear++;
		return;
	}

	void dequeue(){
		if(rear == 0){
			cout << "Queue is empty" << endl;
			return;
		}
		for(int i=0; i<rear-1; i++){
			queue[i] = queue[i+1];
		}
		rear--;
		return;
	}

	int queueFront(){
		if(rear == 0){
			cout << "Queue is empty" << endl;
			return INT_MIN;
		} 
		return queue[front];
	}

	bool isEmpty(){
		return front == 0;
	}

	void displayQueue(){
		if(front == rear){
			cout << "Queue is empty" << endl;
			return;
		}
		for(int i=front; i<rear; i++){
			cout << queue[i] << " <-- ";
		}
		cout << endl;
		return;
	}


};

int main(){
	Queue q(4);
	q.enqueue(10);
	q.enqueue(11);
	q.enqueue(12);
	q.enqueue(15);
	q.enqueue(100);
	q.displayQueue();
	q.dequeue();
	cout << "Queue after moving front" << endl;
	q.displayQueue();
	cout << q.queueFront() << endl;
	return 0;
}