#include<iostream>
using namespace std;

class Node 
{
    public:
    int co;
    int pow;
    Node *next;
    Node()
    { co = 0; pow=0; next = NULL;}
    Node(int co, int pow)
    {
        this->co = co;
        this->pow = pow;
        next = NULL;
    }
};

class LL{
    public:
    Node *head;
    LL()
    {
        head = NULL;
    }
    void insertatbegin(int co, int pow)
    {
        Node *newnode = new Node(co, pow);
        if(head == NULL)
            head = newnode;
        else{
            newnode->next = head;
            head = newnode;
        }
    }
    void display()
    {
        Node *temp = head;
        while(temp != NULL)
        {
            cout<<temp->co<<"^"<<temp->pow<<"\t";
            temp = temp->next;
        }
    }
    void addpoly(Node *head1, Node *head2, Node *result)
    {
       // Node *result;
        Node * temp1= head1;
        Node *temp2 = head2;
        while(temp1->next && temp2->next)
        {
            if(temp1->pow > temp2->pow)
            {    result->co = temp1->co;
                 result->pow = temp1->pow;  
                 temp1  = temp1->next; 
            }
            else if(temp1->pow == temp2->pow)
            {
                result->co = temp1->co + temp2->co;
                 result->pow = temp1->pow;  
                 temp1 = temp1->next;
                 temp2 = temp2->next;

            }
            else{
                result->co = temp1->co;
                result->pow = temp1->pow; 
                temp2 = temp2->next;
            }
            result->next = new Node();
            result = result ->next;
        }


    }
};
int main()
{
    LL p1, p2;
    p1.insertatbegin(1,1);
    p1.insertatbegin(3,2);
    p1.insertatbegin(4,3);
    p1.display();
    p2.insertatbegin(1,2);
    p2.insertatbegin(3,3);
    p2.insertatbegin(4,4);
    p2.display();

}