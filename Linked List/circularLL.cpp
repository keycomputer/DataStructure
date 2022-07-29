#include<iostream>
using namespace std;

//node structure
struct Node {
    int data;
    Node* next;
    
};

class LinkedList {
  public:
    Node* head;
  public:
    //constructor to create an empty LinkedList
    LinkedList(){
      head = NULL;
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
};
