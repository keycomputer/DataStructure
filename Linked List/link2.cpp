#include<iostream>
using namespace std;

struct Node 
{
    char data;
    Node *next;
    Node(char elem)
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
    void insertatbegin(char elem)
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
    // ABCDEFGH
    //  CABC
    void remove(LL obj)
    {
        Node *p1 = head, *p2 = obj.head;


        while(p2 != NULL)
        {
            Node *p2 = obj.head;
            while(p1 != NULL)
            {
                if(p2  == NULL)
                    break; //return false;
                else if (p1->data  == p2->data)
                {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                else
                    break;
            }
            if(p1== NULL)
                break;
            p1= head;
            p2 = 
        }
    }
    void remove(LL obj)
    {
        int c;
        Node *temp = head, *temp1=obj.head, *start;
        while(temp1!= NULL)
        {
            temp = head;
            c=3;
            while(temp !=NULL)
            {
                if (temp->data == temp1->data)
                {
                    break;
                }
                temp = temp->next;
            }
            start = temp1;
            Node * start2 = temp;
            while(temp!=NULL && c>=1 && temp->data == start->data)
            {
                temp = temp->next;
                start = start ->next;
                c--;
            }
            if(c == 0)
            {
                while(start2 !=NULL && c<3){
                       Node *temp2 = start2;
                       
                       if(start2 == head)
                        {
                            head = head ->next;
                            delete temp2;
                        }
                        else{
                       start2 = temp2->next;
                       delete temp2;
                        }
                    
                }

            }
            temp1= temp1->next;
        }

    }
};
int main()
{
    LL obj1, obj2;
    string s1, s2;
    cin>>s1;
    for(int i=0;i<s1.length();i++) 
        obj1.insertatbegin(s1[i]);
    cin>>s2;
    for(int i=0;i<s2.length();i++) 
        obj2.insertatbegin(s2[i]);
    
    obj1.remove(obj2);
    obj1.display();


}