#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(int elem)
    {
        data = elem;
        next = NULL;
    }
};

class LL{
    public:
    Node *head;
    Node *l1;
    Node *l2;
    LL()
    {
        head = NULL;
        l1 = l2 = NULL;
    }
    Node * insertatbegin(Node *head, int elem )
    {
        Node *newnode = new Node(elem);
        if(head == NULL)
            head = newnode;
        else
        {
            newnode->next = head;
            head = newnode;
        }
        return head;
    }
    Node * insertatend(Node *head , int elem)
    {
        Node *newnode = new Node(elem);
        if(head == NULL)
            head = newnode;
        else
        {
            Node *temp= head;
            while(temp->next != NULL)
            {
                temp= temp->next;
            }
            temp->next = newnode;   
        }
        return head;
    }
    void display(Node * head)
    {
        Node *temp;
        temp  = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"\t";
            temp= temp->next;
        }
    }
    void split()
    {
        Node *temp = head, *temp1, *newnode;
        while(temp != NULL)
        {
            l1 = insertatend(l1, temp->data);
             temp = temp->next;
            if(temp == NULL)
                break;
            l2= insertatend(l2, temp->data);
            temp = temp->next;
        }
    }
};

int main()
{
    LL obj;
    obj.head = obj.insertatbegin(obj.head, 7);
    obj.head = obj.insertatbegin(obj.head, 6);
    obj.head = obj.insertatbegin(obj.head,5);
    obj.head = obj.insertatbegin(obj.head,4);
    obj.head = obj.insertatbegin(obj.head, 3);
    obj.head = obj.insertatbegin(obj.head, 2);
    obj.head  = obj.insertatbegin(obj.head, 1);
    obj.display(obj.head);
    obj.split();
    obj.display(obj.l1);
    obj.display(obj.l2);
    

}
