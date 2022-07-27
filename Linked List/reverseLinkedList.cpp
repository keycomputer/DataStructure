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
    LL()
    {
        head = NULL;
    }
    void insertatbegin(int elem )
    {
        Node *newnode = new Node(elem);
        if(head == NULL)
            head = newnode;
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    void display(Node * temp)
    {
       if (temp ==NULL)
        {
            return;
        }
            cout<<temp->data<<"\t";
            display(temp->next);
    }
    
    // Display in reverse Order 

    void displayrev(Node * temp)
    {
       if (temp ==NULL)
        {
            return;
        }
            display(temp->next);
            cout<<temp->data<<"\t";
    }
    // reverse Linked List using three Pointers  
    void reverse()
    {
        Node *cur = head;
        Node *prev , *next;
        prev= next = NULL;
        while(cur != NULL)
        {
            next = cur -> next;
            cur->next= prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    // Reverse Linked List using recursion 
    Node * reverse1(Node *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        else
        {
            Node *temp = reverse1(head->next);
            cout<<head->data <<"\t"<<head->next->data<<endl ;
            head->next->next = head;
            head->next= NULL;       
            return temp;
        }
    }

    void insertatend(int elem)
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
    }
    int countNode()
    {
        Node *temp;
        temp  = head;
        int c=0;
        while(temp != NULL)
        {
            c++;
            temp= temp->next;
        }
        return c;
    }
    void insertatpos(int elem, int pos)
    {
        Node *newnode = new Node(elem);

        if(head == NULL)
            head = newnode;
        else{
            int c=1;
            Node *temp = head , *prev;
            while(temp!=NULL && c < pos)
            {
                c++;
                prev = temp;
                temp = temp->next;
            }
            newnode->next = temp;
            prev->next = newnode;
        }
    }
    void deletebegin()
    {
        Node *temp;
        if(head == NULL)
        {
            cout<<"Empty ";
            return;
        }
        // else if (head->next == NULL)
        // {
        //     temp = head;
        //     head= NULL;
        //     delete temp;
        // }
        else{
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void deleteend()
    {
        Node *temp1, *temp2;
        if(head == NULL)
        {
            cout<<"Empty ";
            return;
        }
        else{
            temp1 =head;
            while(temp1->next->next!=NULL)
            {
                temp1 = temp1->next;
            }       
            temp2 = temp1->next;
            delete temp2;
            temp1->next = NULL;
        }
        
    }
    
};

int main()
{
    LL obj;
    obj.insertatbegin(10);
    obj.insertatbegin(11);
    obj.insertatbegin(12);
    obj.insertatbegin(13);
    obj.insertatpos(15,2);
    obj.insertatend(14);
    
    obj.reverse();

    obj.head = obj.reverse1(obj.head);
    obj.display(obj.head);
    cout<<endl;

    obj.displayrev(obj.head);

}