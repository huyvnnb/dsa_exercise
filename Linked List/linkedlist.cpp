#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node(int x) : data(x), next(NULL) {}
};

void pushFront(node **head, int x){
	node *newNode = new node(x);
	newNode->next = *head;
	(*head) = newNode;
}

void insertNode(node *prev, int x){
	node *newNode = new node(x);
	newNode->next = prev->next;
	prev->next = newNode;
}

void printList(node *head){
	while(head!=NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

bool search(node *head, int key){
	if(head==NULL){
		return false;
	}
	if(head->data == key){
		return true;
	}
	return search(head->next, key);
}

void reverse(node **head){
	node *prev = NULL;
	node *curr = *head;
	node *next = (*head)->next;
	while(next != NULL){
		curr->next = prev;
		prev = curr;
		curr = next;
		next = next->next;
	}
	curr->next = prev;
	*head = curr;
}

void printMiddle(node *head){
	node *slow_node = head;
	node *fast_node = head;
	if(head==NULL){
		cout << "EMPTY" << endl;
		return;
	}
	while( fast_node != NULL && fast_node->next != NULL ){
		fast_node = fast_node->next->next;
		slow_node = slow_node->next;
	}
	cout << slow_node->data << endl;
}

void printMiddle2(node *head){
	int cnt=0;
	node *middle = head;
	while(head!=NULL){
		head = head->next;
		if(cnt & 1){
			middle = middle->next;
		}
		cnt++;
	}
	cout << middle->data << endl;
}


void printNthFromLast(node* head, int N)
{
    static int i = 0;
    if (head == NULL)
        return;
    printNthFromLast(head->next, N);
    if (++i == N)
        cout<<head->data;
}

int main(){
	node *head = nullptr;
	pushFront(&head, 10);
	pushFront(&head, 30);
	pushFront(&head, 11);
	pushFront(&head, 41);

	printList(head);
	
	printMiddle2(head);

	printNthFromLast(head, 3);

	return 0;
}
