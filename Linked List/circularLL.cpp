#include<iostream>
using namespace std;

//node structure
struct Node {
    int data;
    Node* next;
  Node(int elem)
  {
    data = elem;
    next = NULL;
  }    
};

class LinkedList {
  public:
    Node* head;
  public:
    //constructor to create an empty LinkedList
    LinkedList(){
      head = NULL;
    }
    void insertatbegin(int elem)
    {
      Node *newnode = new Node (elem);
      if(head == NULL)
      {
         head = newnode;
         head->next = head;
      }
      else{
          Node *temp = head;
          while(temp->next!=head)
          {
            temp= temp->next;
          }
          temp->next= newnode;
          newnode->next= head;
          head= newnode;
      }
    }
    void insertatpos(int elem, int pos)
    {
      Node *newnode = new Node (elem);
      Node *temp = head;
      int count = 1;
      if(temp!= NULL)
        temp = temp->next;
      while(temp!=head)
      { 
        count++;
        temp= temp->next;
      }
      if(pos < 1 || count <pos)
        cout<<"Invlaid ";
      else if (pos ==1)
      {
        insertatbegin(elem);
      }
      else{
        temp= head;
        for(int i =1; i<pos-1;i++)
          temp= temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
      }
    }
    void insertatend(int elem)
    {
      Node *newnode = new Node(elem);
      if (head == NULL)
      {
        head = newnode;
         head->next = head;
      }
      else{
          Node *temp = head;
          while(temp->next!=head)
          {
            temp= temp->next;
          }
          temp->next= newnode;
          newnode->next= head;
      }
    }
    void PrintList() {
      Node* temp = head;
      if(temp != NULL) {
        cout<<"The list contains: ";
        while(true) {
          cout<<temp->data<<" ";
          temp = temp->next;
          if(temp == head) 
            break;
        }
        cout<<endl;
      } else {
        cout<<"The list is empty.\n";
      }
    }  

    // void deleteAllNodes() {
    //   if(head != NULL) {
        
    //     //1. if head is not null create a temp node
    //     //   and current node pointed to next of head
    //     Node *temp, *current;
    //     current = head->next;
        
    //     //2. if current node is not equal to head, delete the
    //     //   current node and move current to next node using temp,
    //     //   repeat the process till the current reaches the head
    //     while(current != head) {
    //       temp = current->next;
    //       free(current);
    //       current = temp;
    //     }

    //     //3. Delete the head
    //     free(head);
    //     head = NULL;
    //   }
    //   cout<<"All nodes are deleted successfully.\n";  
    // }   
    // int countNodes() {
      
    //   //1. create a temp node pointing to head
    //   Node* temp = head;

    //   //2. create a variable to count nodes
    //   int i = 0;
      
    //   //3. if the temp node is not null increase 
    //   //   i by 1 and move to the next node, repeat
    //   //   the process till the temp becomes null
    //   if(temp != NULL) {
    //     i++;
    //     temp = temp->next;
    //   }
    //   while(temp != head) {
    //     i++;
    //     temp = temp->next;
    //   }

    //   //4. return the count
    //   return i;  
    // } 
    // void deleteEvenNodes() {
    //   if(head != NULL && head->next != head) {
      
    //     //1. if the list has more than one element
    //     //   create evenNode node - pointing to head
    //     //   oddNode node - pointing to next of head
    //     //   temp node - to store last odd node
    //     Node* oddNode = head;
    //     Node* evenNode = head->next; 
    //     Node* temp = new Node(elem);

    //     while(true) {
          
    //       //2. delete even node and update evenNode and 
    //       //   oddNode to next set of odd-even nodes
    //       //   update temp node to latest oddNode node
    //       //   continue the process till any of the node 
    //       //   reaches head
    //       temp = oddNode;
    //       oddNode->next = evenNode->next;
    //       free(evenNode);
    //       oddNode = oddNode->next;
    //       evenNode = oddNode->next;
    //       if(oddNode == head || evenNode == head)
    //         break;
    //     }
        
    //     //3. if oddNode reaches head, make next of 
    //     //   temp as head else make next of oddNode
    //     //   as head
    //     if(oddNode == head)
    //       temp->next = head;
    //     else
    //       oddNode->next = head;
    //   }
    // } 
    // void concat(LinkedList L2)
    // {
    //    Node * temp = head;
    //    while(temp->next != head)
    //    {
    //       temp= temp->next;
    //    }
    //    Node *temp2 = L2.head;
    //    while(temp2->next != head)
    //    {

    //    }
    // }
    void deletefront()
    {
      if(head != NULL)
      {
        if(head->next == head)
          head = NULL;
      }
      else{
        Node *temp = head;
        Node *first = head;
        while(temp->next != head)
          temp = temp->next;
        head = head->next;
        temp -> next = head;
        delete first;
      }
    }
    void deleteback()
    {
      if(head!= NULL)
      {
        if(head->next == head)
          head = NULL;
      }
      else
      {
        Node *temp = head;
        while(temp->next->next != head)
          temp = temp->next;
        Node *last = temp->next;
        temp->next = head;
        delete last;
      }
    }
    void deleteatpos(int pos)
    {
      Node *temp1 = head;
      Node *temp = head;
      int count =0;
      if(temp != NULL)
      {
        count++;
        temp = temp->next;
      }
      while(temp != head)
      {
        count++;
        temp = temp->next;
      }
      if(pos<1 || pos > count)
        cout<<"invalid ";
      else if(pos == 1)
      {
        if(head ->next == head)
          head = NULL;
        else
        {
        
          while(temp->next != head)
            temp = temp->next;
          Node *temp1 = head;
          head = head->next;
          temp-> next = head;
          delete temp1;
        }
      }
      else{
        temp = head; 
        for(int i=1; i<pos-1 ; i++)  // 0 - pos-2
          temp = temp ->next;
        temp1 = temp->next;
        temp->next = temp ->next->next;
        delete temp1;
      }
    }
    void deleteallnode()
    {
      if(head != NULL)
      {
        Node * temp, *cur;
        cur = head->next;
        while(cur != head)
        {
          temp = cur;
          cur = cur->next;
          delete temp;
        }
        delete head;
        head= NULL;
      }
    }
    void countNode()
    {
      Node *temp = head;
      int i=0;
      if(temp != NULL)
      {
        i++;
        temp= temp->next;
      }
      while(temp != head)
      {
        i++;
        temp = temp->next;

      }
      cout<<"Count = " <<i<<endl;
    }
    Node * concate(LinkedList L)
    {
      Node *temp1 = head;
      
      while(temp1->next != head)
      {
        cout<<temp1->data;
        temp1= temp1->next;
      }
      Node *temp2 = L.head;
      while(temp2->next!= L.head)
      {
        cout<<temp2->data;
        temp2= temp2->next;
      }
      temp1->next = L.head;
      temp2->next = head;
      return head;
    }
};
int main()
{
 LinkedList l;
 l.insertatbegin(1);
 l.insertatbegin(2);
 l.insertatbegin(3);
 l.PrintList();
 LinkedList l2;
 l2.insertatbegin(4);
 l2.insertatbegin(5);

 l2.PrintList();
//  l.deleteatpos(1);
//  cout<<endl;
//  l.PrintList();
//  l.countNode();
 l2.head = l2.concate(l);
 l2.PrintList();

}