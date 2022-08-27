#include<iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next;
    Node(int elem)
    {
        data = elem;
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
    void insertatbegin(int elem)
    {
        Node *newnode = new Node(elem);
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
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
    }
    // ////////// using recursion 
    // void display(Node * temp)
    // {
    //     if(temp == NULL)
    //         return;
    //     else{
    //         cout<<temp->data<<"\t";
    //         display(temp->next);
    //     }
    // }
    void insertatend(int elem)
    {
        Node *newnode = new Node(elem);
        if(head == NULL)
            head = newnode ;
        else
        {
            Node *temp = head;
            while(temp->next != NULL)
            {
                temp= temp->next;
            }
            temp->next = newnode;
        }
    }
    void insertatpos(int elem, int pos)
    {
        Node *newnode = new Node(elem);
        if (pos == 1)
            insertatbegin(elem);
        else{
            Node *temp  = head;
            for(int i=0;i<pos-2;i++)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    void deletebegin()
    {
        if(head == NULL)
            cout<<"Empty list";
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void deleteend()
    {
        Node *temp;
        if(head == NULL)
            cout<<"Empty list";
        else if(head->next == NULL)
        {
            temp= head;
            head= NULL;
            delete temp;
        }
        else
        {
            temp=head;
            while(temp->next->next!= NULL)
                temp = temp->next;
            Node *temp1 = temp->next;
            temp->next = NULL;
            delete temp1;

        }
    }
    void deletepos( int pos)
    {
        Node *temp;
        if(head == NULL)
            cout<<"Empty list";
        else
        {
            if (pos == 1)
            {
                deletebegin();
            }
            else
            {
                temp = head;
                for(int i=0;i<pos-2;i++)
                {
                    temp = temp->next;
                }
                Node * temp2 = temp->next;
                temp->next = temp2->next; // temp->next = temp->next->next;
                delete temp2;

            }
        }
    }
    void deleteodd()
    {
        Node *temp ;
        while(1)
        {
            if(head->data % 2 != 0)
            {
                temp  = head;
                head = head->next;
                delete temp;
            }
            else
                break;
        }
        Node * prev= head;
        temp = head->next;
        if(head != NULL){
        while(1)
        {
            if (temp == NULL || prev -> next == NULL )
                break;
            if(temp->data%2 != 0)
            {
                prev->next = temp->next;   
                delete temp;
            }
            temp = prev->next;

        }
        }
    }
};
int main()
{
    LL obj;
    obj.insertatbegin(2);
    obj.insertatbegin(5);
    obj.insertatbegin(30);
    obj.insertatbegin(7);
    obj.insertatend(9);
    obj.insertatpos(11,3);
    // obj.display(obj.head);
    // cout<<endl;
    // obj.deletebegin();
    // obj.deleteend();
    // // obj.display(obj.head);
    // obj.deletepos(3);
    // obj.display(obj.head);
    obj.display();
    obj.deleteodd();
    cout<<endl;
    obj.display();

}