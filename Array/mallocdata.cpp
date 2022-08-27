#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    Node *next; 
    Node(int elem)
    {
        data = elem;
    }
}Node;
void insertatend(Node *head, int elem)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    
}
int main()
{
    Node *head = NULL;
    insertatend(head,1);

}