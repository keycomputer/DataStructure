#include<iostream>

using namespace std;

class Queue
{
    int front, rear;
    int arr[10];
    public:
    Queue()
    { front = rear = -1;}
    bool isfull()
    {
        if (rear == 9)
            return true;
        return false;
    }
    void enqueue(int elem)
    {
        if(isfull())
            cout<<"\nOverflow ";
        else
        {
            if(front == -1)
                front= rear =0;
            else
                rear++;
            arr[rear] = elem;
        }
    }
    void dequeue()
    {
        if(rear == -1)
            cout<<"\nUnderflow";
        else if (front== rear){
            cout<<"\ndeleting "<<arr[front];
            front= rear = -1;
        }
        else
        {
            cout<<"\ndeleting "<<arr[front];
            front++;
        }
    }
    void display()
    {
        for(int i=front ; i<= rear;i++)
            cout<<arr[i]<<"\t";
        cout<<endl;
    }
};

int main()
{
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    
}
