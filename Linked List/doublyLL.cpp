
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
    Node * head;
    public:
    DLL(){
        head = NULL;
    }

    void insertatbegin(int elem){
        Node *newnode = new Node(elem);
        if(head == NULL)
            head= newnode;
        else
        {
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
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
    void insertatpos(int elem,int  pos)
    {
        Node *newnode = new Node(elem);
        if(pos <1)
            cout<<"Invalid ";
        else if (pos ==1)
            insertatbegin(elem);
        else
        {
            Node *temp = head;
            for(int i=1;i<pos-1 && temp!=NULL; i++)
            {
                temp= temp->next;
            }
            if(temp==NULL)
            {
                cout<<"invalid Pos";
            }
            else
            {
                newnode->next = temp->next;
                newnode->prev = temp;
                temp->next= newnode;
                if(newnode->next != NULL)
                    newnode->next->prev = newnode;
                
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
    void deletebegin()
    {
        if(head == NULL)
            cout<<"List empty ";
        else
        {
            Node *temp = head;
            head = temp->next; // head = head->next;
            delete temp;
            head -> prev = NULL;
        }
    }
    void deleteend()
    {
        Node *temp;
        if(head == NULL)
            cout<<"List empty ";
        else
        {
            if(head->next==NULL)
            {
                temp= head;
                delete  temp;
                head =NULL;
            }
            else{
            temp= head;
            while(temp->next != NULL)
            {
                temp  = temp->next;
            }
            // Node *prev = temp->prev;
            // prev->next= NULL;
            temp->prev->next = NULL;
            delete temp;
            }
        }
    }
    void deleteatpos(int pos)
    {
        if (pos<1)
            cout<<"invlaid";
        else if(pos ==1 )
            deletebegin();
        else{
            Node *temp = head;
            for(int i =1;i<pos-1 && temp != NULL ;i++)
                temp = temp->next;
            if(temp == NULL || temp->next == NULL)
            {
                cout<<"Invalid Pos";
            }
            else
            {
                Node *temp1 = temp->next;
                temp->next = temp->next->next ; // = temp1->next;
                if(temp->next->next != NULL)
                    temp->next->next->prev = temp;
                delete temp1;
            }
        }
    }
};
int main()
{
    DLL obj;
    obj.insertatbegin(1);
    obj.insertatbegin(2);
    obj.insertatbegin(3);
    obj.insertatpos(4, 2);
    obj.insertatend(5);
    obj.print();
    cout<<endl;
    obj.deletebegin();
    obj.deleteend();
    obj.deleteatpos(2);
    obj.print();
}