#include <bits/stdc++.h>
using namespace std;

// struct node{
// 	int data;
// 	vector<node *> child;
// };

// node *newNode(int data){
// 	node *temp = new node;
// 	temp->data = data;
// 	return temp;
// }

// int depthOfTree(node *ptr){
// 	if(!ptr){
// 		return 0;
// 	}
// 	int maxdepth = 0;
// 	for(vector<node*>::iterator it = ptr->child.begin(); it != ptr->child.end(); it++){
// 		maxdepth = max(maxdepth, depthOfTree(*it));
// 	}
// 	return maxdepth+1;
// }
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


int findDepth2(node *root, int key){
	if(root == NULL){
		return -1;
	}
	if(root->data == key){
		return 0;
	}
	int leftDepth = findDepth2(root->left, key);
	int rightDepth = findDepth2(root->right, key);

	if(leftDepth == -1 && rightDepth == -1){
		return -1;
	}
	else{
		return max(leftDepth, rightDepth)+1;
	}
}

int findDepth3(node *root, int key){
	if(root == NULL){
		return -1;
	}
	int dist = -1;
	if(root->data == key
		|| (dist = findDepth3(root->left, key)) >= 0
		|| (dist = findDepth3(root->right, key)) >= 0){
		return dist + 1;
	}
	return dist;
}

int findHeightUtil(node *root, int key, int &height){
	if(root == NULL){
		return -1;
	}
	int leftHeight = findHeightUtil(root->left, key, height);
	int rightHeight = findHeightUtil(root->right, key, height);

	int ans = max(leftHeight, rightHeight) + 1;
	if(root->data == key){
		height = ans;
	}
	return ans;
}

int findHeight(node *root, int key){
	int h = -1;
	findHeightUtil(root, key, h);
	return h;
}

int findDepth4(node *root, int key) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == key) {
        return 0;
    }
    int leftDepth = findDepth4(root->left, key);
    if (leftDepth != -1) {
        return leftDepth + 1;
    }
    int rightDepth = findDepth4(root->right, key);
    if (rightDepth != -1) {
        return rightDepth + 1;
    }
    return -1;
}

void find_height_and_depth(node *root, int key){
	queue<node *> q;
	if(root==NULL){
		cout << "EMPTY" << endl;
		return;
	}
	q.push(root);
	int depth = -1;
	int height = -1;
	int level = 0;
	while(!q.empty()){
		int n = q.size();
		for(int i=0; i<n; i++){
			node *front_node = q.front();
			q.pop();
			if(front_node->data == key){
				depth = level;
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
	if(depth == -1){
		cout << "NOT FOUND" << endl;
		return;
	}
	height = level-depth-1;
	cout << "Depth is: " << depth << endl;
	cout << "Height is: " << height << endl;
}

int main(){
	node *root = new node(1);
	root->left = new node(4);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->left->left = new node(7);
	root->left->left->left->left = new node(4);
	int key = 10;

	find_height_and_depth(root, key);
	return 0;
}