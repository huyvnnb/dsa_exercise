#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

int findLevel(node *root, int key){
	if(root==NULL){
		return -1;
	}
	int level = 0;
	if(root->data == key){
		return level+1;
	}
	int lLevel = findLevel(root->left, key);
	int rLevel = findLevel(root->right, key);
	if((lLevel == -1 && rLevel == -1)){
		return -1;
	}
	else{
		return max(lLevel, rLevel)+1;
	}
}

int getLevelUntil(node *root, int key, int level){
	if(root == NULL){
		return 0;
	}
	if(root->data == key){
		return level;
	}

	int downlevel = getLevelUntil(root->left, key, level+1);
	if(downlevel != 0){
		return downlevel;
	}
	downlevel = getLevelUntil(root->right, key, level+1);
	return downlevel;
}
 int getLevel(node *root, int key){
 	return getLevelUntil(root, key, 1);
 }

int get_level_use_queue(node *root, int key){
	if(root == NULL){
		return 0;
	}
	queue<node *> q;
	q.push(root);
	int level = 1;
	while(!q.empty()){
		int n = q.size();
		for(int i=0; i<n; i++){
			node *front_node = q.front();
			q.pop();
			if(front_node->data == key){
				return level;
			}
			if(front_node->left){
				q.push(front_node->left);
			}
			if(front_node->right){
				q.push(front_node->right);
			}
		}
		level++;
	}
	return 0;
}

bool isExist(node *root, int key){
	if(root == NULL){
		return false;
	}
	if(root->data == key){
		return true;
	}
	bool res1 = isExist(root->left, key);
	if(res1){
		return true;
	}
	res1 = isExist(root->right, key);
	return res1;
}

int main(){
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(9);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->left->left = new node(7);

	for(int i = 1; i<=10; i++){
		bool check = isExist(root, i);
		if(check){
			cout << i << " is exist" << endl;
		}
		else{
			cout << i << " is not exist" << endl;
		}
	}
	return 0;
}