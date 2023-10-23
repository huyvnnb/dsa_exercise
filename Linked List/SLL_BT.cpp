#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

node *makeNode(int x){
	node *temp = new node;
	temp->data = x;
	temp->next = NULL;
	return temp;
}

int size(node *head){
	int cnt = 0;
	while(head!=NULL){
		cnt++;
		head = head->next;
	}
	return cnt;
}

void pushFront(node **head, int x){
	node *temp = makeNode(x);
	temp->next = *head;
	*head = temp;
}

void pushBack(node **head, int x){
	node *newNode = makeNode(x);
	if(*head == NULL){
		*head = newNode;
		return ;
	}
	node *temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void insert(node **head, int pos, int x){
	int n = size(*head);
	if(pos<1 || pos > n){
		cout << "INVALID" << endl;
		return ;
	}
	if(pos == 1){
		pushFront(head, x);
		return;
	}
	if(pos == n){
		pushBack(head, x);
		return;
	}
	node *temp = *head;
	for(int i=1; i<= pos-2; i++){
		temp = temp->next;
	}
	node *newNode = makeNode(x);
	newNode->next = temp->next;
	temp->next = newNode;
}

void popFront(node **head){
	if(*head==NULL)
		return;
	 node *temp = *head;
	 *head = (*head)->next;
	 delete temp;
}

void popBack(node **head){
	if(*head == NULL) return;
	node *temp = *head;
	if(temp->next==NULL){
		*head = NULL;
		delete temp;
		return;
	}
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	node *last = temp->next;
	temp->next = NULL;
	delete last;
}

void erase(node **head, int pos){
	int n = size(*head);
	if(*head == NULL || pos < 1 || pos > n){
		return;
	}
	if(pos==1){
		popFront(head);
		return;
	}
	node *temp = *head;
	for(int i=1; i<= pos-2; i++){
		temp = temp->next;
	}
	node *deleteNode = temp->next;
	temp->next = temp->next->next;
	delete deleteNode;
}

void printList(node *head){
	if(head==NULL){
		cout << "Empty list" << endl;
		return;
	}
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}


int main(){
	node *head = NULL;
	while(true){
		cout << "-----------------------------------------------\n";
		cout << "1. Them vao dau\n";
		cout << "2. Them vao cuoi\n";
		cout << "3. Them vao giua\n";
		cout << "4. Xoa phan tu dau\n";
		cout << "5. Xoa phan tu cuoi\n";
		cout << "6. Xoa phan tu giua\n";
		cout << "7. In danh sach\n";
		cout << "8. Ket thuc chuong trinh\n";
		cout << "-----------------------------------------------\n";

		int choice; cin >> choice;
		if(choice == 1){
			int x; cout << "Nhap x: ";
			cin >> x;
			pushFront(&head, x);
		}
		else if(choice==2){
			int x; cout << "Nhap x: ";
			cin >> x;
			pushBack(&head, x);
		}
		else if(choice==3){
			int x; cout << "Nhap x: ";
			cin >> x;
			int pos; cout << "Nhap vi tri: "; cin >> pos;
			insert(&head, pos, x);
		}
		else if(choice==4){
			popFront(&head);
		}
		else if(choice==5){
			popBack(&head);
		}
		else if(choice==6){
			int pos;
			cout << "Nhap vi tri: "; cin >> pos;
			erase(&head, pos);
		}
		else if(choice==7){
			printList(head);
		}
		else if(choice==8){
			break;
		}
	}


	return 0;
}