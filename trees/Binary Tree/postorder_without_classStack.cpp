#include <stdio.h>
#include<iostream>
using namespace std;
#define MAX_SIZE 100
 
class Node
{
    public:
    int data;
    Node *left, *right;
};
 
class Stack
{
    public:
    int size;
    int top;
    Node* *array;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Stack* createStack(int size)
{
    Stack* stack = new Stack;
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node**) malloc(stack->size * sizeof(struct Node*));
    return stack;
}
 
int isFull(struct Stack* stack)
{ return stack->top - 1 == stack->size; }
 
int isEmpty(struct Stack* stack)
{ return stack->top == -1; }
 
void push(struct Stack* stack, struct Node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}
 
struct Node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}
 
struct Node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}
 
void postOrderIterative(struct Node* root)
{
    if (root == NULL)
        return;
     
    Stack* stack = createStack(MAX_SIZE);
    do
    {
        while (root)
        {
            if (root->right)
                push(stack, root->right);
            push(stack, root);
 
            root = root->left;
        }
 
        root = pop(stack);
 
        if (root->right && peek(stack) == root->right)
        {
            pop(stack); 
            push(stack, root); 
            root = root->right; 
            
        }
        else 
        {
            cout<<root->data<<" ";
            root = NULL;
        }
    } while (!isEmpty(stack));
}
 

int main()
{
    //            10
    //      20        30
    //    40  50     60    70
    Node* root = NULL;
    root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);
    cout<<"Post order traversal of binary tree is :\n";
    cout<< "[";
    postOrderIterative(root);
    cout<<"]";
     
 
    return 0;
}