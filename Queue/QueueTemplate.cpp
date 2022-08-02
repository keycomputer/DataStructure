
#include<iostream>
using namespace std;

template<typename t>
class Queue
{
    t *arr;
    int front , rear;
    int n;
    public:
    Queue()
    {
        cout<<"Enter no of elements (Capacity )::  ";
        cin>>n;
        arr = new t[n];
        front = rear = -1;
    }
    bool isfull()
    {
        if(rear ==n-1 )
            return true;
        return false;
    }
    void enqueue(t elem){
        if(isfull())
            cout<<"Overflow ";
        else
        {
            if(front == -1 && rear == -1)
                front = rear = 0;
            else
                rear++;
            arr[rear] = elem;
        }
    }
    bool isempty()
    {
        if (front == -1 && rear == -1)
            return true;
        return false;
    }
    t dequeue()
    {
        if (isempty())
        {
            cout<<"Underflow";
            return -1;
        }
        else
        {
            t elem = arr[front];
            front++;
            if(front > rear)
                front= rear =-1;
            return elem;
        }
    }
    void display()
    {
        for(int i=front; i<=rear;i++)
            cout<<arr[i]<<"\t";
    }
};
int main()
{
    Queue <int> obj;
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    cout<<obj.dequeue();
    cout<<obj.dequeue();
    cout<<obj.dequeue();
}