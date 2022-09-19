
#include<iostream>
using namespace std;

class Node
{   public:
    int data;
    Node *prev, *next;
    Node(int elem){
        data = elem; 
        next= prev=NULL;
    }
};
class DLL
{
    public:
    Node * head;
    public:
    DLL(){
        head = NULL;
    }

    void insertatend(int elem)
    {
        Node *newnode = new Node(elem);
        if(head == NULL)
            head= newnode;
        else
        {
            Node * temp = head;
            while(temp->next!=NULL)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
    Node * seg()
    {
        Node *temp1, *temp2;
        Node *evenhead=NULL, *eventail , *oddhead=NULL, *oddtail;
        temp1 = head;
        while(temp1 != NULL)
        {
            if(temp1->data % 2 == 0)
            {
                if (evenhead == NULL)
                    evenhead = eventail= temp1;

                else
                {
                    eventail ->next = temp1;
                    eventail = temp1;
                }
            }
            else{
                if (oddhead == NULL)
                    oddhead = oddtail= temp1;
                else
                {
                    oddtail ->next = temp1;
                    oddtail = temp1;
                }
            }
            temp1 = temp1 ->next;
        }
        eventail ->next = oddhead;
        oddhead->prev = eventail;
        oddtail->next= NULL;
        return evenhead;
        

    }
    void print()
    {
        Node *temp = head;
        if (temp == NULL)
            cout<<"List is empty ";
        else{
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        }
    }

};
int main()
{
    DLL obj;
    obj.insertatend(1);
    obj.insertatend(2);
    obj.insertatend(3);
    obj.insertatend(4);
    obj.head = obj.seg();
    obj.print();
}