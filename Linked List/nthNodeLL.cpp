#include<iostream>
using namespace std;
class Node 
{
    public:
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
        cout<<"\nList ::  ";
        while(temp != NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
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
            for(int i=1;i<pos-1;i++)
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
    int nthnode(int index)
    {
        Node *temp = head;
        int count=0;
        while(temp != NULL)
        {
            if(count == index)
                return temp->data;
            temp= temp->next;
            count++;
        }
        return -1;
    }
    int nthnode(Node *temp , int index)
    {
        if(index == 0 )
            return temp->data;
        if(temp == NULL)
            return -1;
        nthnode(temp->next, index-1);
    }
    int nthnodeLast(int index)
    {
        Node *temp= head;
        int count=0;
        while(temp != NULL)
        {
            temp= temp->next;
            count++;
        }
        if(count <= index )
            return -1;
        else{
            temp = head;
            for(int i=0;i<count - index -1 ;i++)
            {
                temp = temp -> next;
            }
            return temp->data;
        }

    }
    int nthnodeLast(Node *temp ,int index)
    {
        static int count = 0;
        if (temp == NULL)   
            return -1;
        
        nthnodeLast(temp->next, index);
        if(count++ == index)
            return temp->data;
    }
    bool iscir()
    {
        Node *temp = head;
        while(temp!= NULL)
        {
            temp = temp->next;
        }
        return false;
    }
};

int main()
{
    LL obj;
    obj.insertatbegin(5);
    obj.insertatbegin(4);
    obj.insertatbegin(3);
    obj.insertatbegin(2);
    obj.insertatbegin(1);
    // int n;
    // cin>>n;
    // if( obj.nthnode(n) == -1)
    //     cout<<"Not Found ";
    // else
    //     cout<<obj.nthnode(n);
    // if( obj.nthnode(obj.head,n) == -1)
    //     cout<<"Not Found ";
    // else
    //     cout<<obj.nthnode(n);
    if(obj.nthnodeLast(2)==-1)
        cout<<"Not Found";
    else
        cout<<obj.nthnodeLast(2);
    if(obj.nthnodeLast(obj.head, 2)==-1)
        cout<<"Not Found";
    else
        cout<<obj.nthnodeLast(2);
    
}