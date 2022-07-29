#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

template <typename TN>
class Node
{
public:
    TN data;
    Node *next;
    Node *prev;
    Node(int d = 0)
    {
        next = NULL;
        prev = NULL;
        data = d;
    }
};

template <typename TL>
class LinkedList
{
    Node<TL> *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void print();
    void printRev();
    int coutNode();
    int maxNode();
    int minNode();

    void push_back(TL);
    void pop_back();
    void push_front(TL);
    void push(int, TL);
    void storeDigits(int);

    void deleteElement(int);
    void swapExtream();
};
template <typename TL>
void LinkedList <TL> :: push_back(TL data)
{
    if (!head)
    {
        head = new Node<TL>(data);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(data);
    newNode->prev = temp;
    temp->next = newNode;
}
template <typename TL>
void LinkedList<TL>::pop_back()
{
    if (!head)
    {
        cout << "List Empty!\n";
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}
template <typename TL>
void LinkedList<TL>::push_front(TL data)
{
    if (!head)
    {
        head = new Node(data);
        return;
    }
    Node *newHead = new Node(data);
    newHead->next = head;
    head->prev = newHead;
    head = newHead;
}
template <typename TL>
void LinkedList<TL>::deleteElement(int index)
{
    if (index < 0)
    {
        cout << "Invalid Index To DeleteElement Function\n";
        return;
    }
    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    Node *temp = head;
    while (index && temp)
    {
        temp = temp->next;
        index--;
    }
    if (temp)
    {
        temp->prev->next = temp->next;
        delete temp;
    }
    else
        cout << "Invalid Index To DeleteElement Function/n";
}
template <typename TL>
void LinkedList<TL>::push(int index, TL data)
{
    if (index < 0)
    {
        cout << "Invalid Index To Push Function/n";
        return;
    }

    if (index == 0)
    {
        push_front(data);
        return;
    }

    Node *temp = head;

    index++;
    while (temp && index)
    {
        temp = temp->next;
        --index;
    }
    cout << temp->data << " ";
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
}
template <typename TL>
void LinkedList<TL>::print()
{
    if (!head)
    {
        cout << "List Empty";
        return;
    }

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
template <typename TL>
void LinkedList<TL>::printRev()
{
    if (!head)
    {
        cout << "List Empty";
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
template <typename TL>
void LinkedList<TL> ::swapExtream()
{
    if (!head)
    {
        cout << "List Empty!\n";
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    swap(temp->data, head->data);
}
int main()
{
    LinkedList<int> *list = new LinkedList<int>();
    list->push_back(10);
    list->push_back(11);
    list->push_back(12);
    list->push_back(14);
    list->push_back(15);
    list->print();
    list->swapExtream();
    list->print();
    return 0;
}