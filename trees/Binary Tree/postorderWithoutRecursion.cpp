#include <bits/stdc++.h>
using namespace std;

// struct Node {

// 	int data;
// 	Node *left, *right;
//     Node () { left=right= NULL;}
//     Node(int data)
//     {
//        	this->data = data;
// 	    left = right = NULL;
//     }
// };
// Node* newNode(int data)
// {
// 	Node* node = new Node(data);
// 	return node;
// }
// void postOrderIterative(Node* root)
// {
// 	if (root == NULL)
// 		return;
// 	stack<Node *> s1, s2;
// 	s1.push(root);
// 	Node* node;
// 	while (!s1.empty()) {
// 		node = s1.top();
// 		s1.pop();
// 		s2.push(node);
// 		if (node->left)
// 			s1.push(node->left);
// 		if (node->right)
// 			s1.push(node->right);
// 	}

// 	while (!s2.empty()) {
// 		node = s2.top();
// 		s2.pop();
// 		cout << node->data << " ";
// 	}
// }

// int main()
// {
// 	Node* root = NULL;
// 	root = newNode(1);
// 	root->left = newNode(2);
// 	root->right = newNode(3);
// 	root->left->left = newNode(4);
// 	root->left->right = newNode(5);
// 	root->right->left = newNode(6);
// 	root->right->right = newNode(7);

// 	postOrderIterative(root);

// 	return 0;
// }

////////// USING ONE STACK
// program to implement post order traversal iteratively using one stack
#include <bits/stdc++.h>
using namespace std;

// structure of a node of a tree
struct Node {
	int data;
	struct Node *left, *right;
};

// function to create new node
struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// function to do post-order traversal
vector<int> postOrderTraversal(struct Node* root)
{
	vector<int> postOrderTraversalNodesList;
	// Check if tree is empty
	if (root == NULL)
		return postOrderTraversalNodesList;
	stack<Node*> stack1;
	stack1.push(root);
	Node* prev = NULL;
	while (!stack1.empty()) {
		auto current = stack1.top();
		if (prev == NULL || prev->left == current
			|| prev->right == current) {
			if (current->left)
				stack1.push(current->left);
			else if (current->right)
				stack1.push(current->right);
			else {
				stack1.pop();
				postOrderTraversalNodesList.push_back(current->data);
			}
		}

		else if (current->left == prev) {
			if (current->right)
				stack1.push(current->right);
			else {
				stack1.pop();
				postOrderTraversalNodesList.push_back(current->data);
			}

		}
		else if (current->right == prev) {
			stack1.pop();
			postOrderTraversalNodesList.push_back(current->data);
		}
		prev = current;
	}
	return postOrderTraversalNodesList;
}

// main funtion to run the program
int main()
{
	// make a tree to traverse
	struct Node* root = NULL;
	root = newNode(15);
	root->left = newNode(10);
	root->right = newNode(23);
	root->left->left = newNode(5);
	root->left->right = newNode(2);
	root->right->left = newNode(9);
	root->right->right = newNode(17);
	printf("Post order traversal: ");
	printf("[");
	vector<int> postOrderTraversalNodesList = postOrderTraversal(root);
	for (auto it : postOrderTraversalNodesList)
		cout << it << " ";
	printf("]");
	return 0;
}


