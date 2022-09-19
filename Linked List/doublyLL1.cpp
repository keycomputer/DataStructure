
#include<iostream>
using namespace std;

struct Node
{   
    int data;
    Node *prev, *next;
    Node(int elem){
        data = elem; 
        next= prev=NULL;
    }
};
class DLL
{
    Node * head, *tail;
    public:
    DLL(){
        head = NULL;
    }

    void insertatend(int elem)
    {
        Node *newnode = new Node(elem);
        if(head == NULL){
            head=tail=newnode;
    
        }
        else
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail= newnode;
        }
    }
    void reverse()
    {
        Node *temp ;
        Node *temp1 = head, *temp2=tail;
        // head 
        if (head == tail)
            return;
        if (head->next->next == NULL)
            {
                temp = head;
                head =tail;
                tail= temp;
                head->next = tail;
                head->prev = NULL;
                tail->prev = head;
                tail->next = NULL;
            }
        else{
        temp1=head;
        temp2=tail;
        // 1 2 3 4

        while(temp1 != temp2 || temp1->prev != temp2)
        {
           if(temp1== head && temp2 == tail)
           {
            {
                temp = head;
                head =tail;
                tail= temp;
                head->next = tail;
                head->prev = NULL;
                tail->prev = head;
                tail->next = NULL;
            }
           }
           temp= temp1;

           temp1->prev = temp2->prev;
           temp1->next = temp2->prev;
           temp2->prev = temp->prev;
           temp2->next = temp->next;
           temp1 = temp2->next;
           temp2= temp1->prev;

        }
        }
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
    obj.reverse();
    obj.print();

}