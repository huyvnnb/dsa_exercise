#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	node(int x){
		data = x;
		left = right = NULL;
	}
};

int find_parent_node2(node *root, int key){
	if(root == NULL){
		return -1;
	}
	if(root->left != NULL && root->left->data == key){
    	return root->data;
    }
    if(root->right != NULL && root->right->data == key){
        return root->data;
    }
	int lNode = find_parent_node2(root->left, key);
	int rNode = find_parent_node2(root->right, key);
	if(lNode == -1 && rNode == -1){
		return -1;
	}
	return max(lNode, rNode);
}

node *find_parent_node_helper(node *root, int key, node *parent){
	if(root == NULL){
		return NULL;
	}
	if(root->data == key){
		return parent;
	}
	node *lNode = find_parent_node_helper(root->left, key, root);
	if(lNode != NULL){
		return lNode;
	}
	node *rNode = find_parent_node_helper(root->right, key, root);
	return rNode;
}

int find_parent_node(node *root, int key){
	node *parent = find_parent_node_helper(root, key, NULL);
	if(parent == NULL){
		return -1;
	}
	return parent->data;
}

int main(){
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(9);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->left->left = new node(7);

	int key = 6;
	cout << find_parent_node(root, key) << endl;
	return 0;
}