#include<iostream>
using namespace std;

class CQ
{
    int front , rear ;
    int arr[5];
    public:
    CQ()
    {front = rear = -1;}
    bool isfull()
    {
        if((front==0 && rear == 4) && (front == rear+1))
            return true;
        return false;
    }
    bool isempty()
    {
        if(front == -1)
            return true;
        return false;
    }
    void enqueue(int elem)
    {
        if(isfull())
            cout<<"Full\n";
        else{
            if(front == -1)
                front = rear = 0;
            else if (rear == 4 && front !=0)
                rear =0;
            else
                rear++;
            arr[rear ]= elem;
        }
    } 
    void dequeue()
    {
        if(isempty())
        {
            cout<<"Empty \n";
        }
        else
        {
            int elem = arr[front];
            cout<<"Deleting "<<elem<<endl;
            if(front == rear)
                front = rear = -1;
            else if(front == 4)
                front =0;
            else
                front++;
            
        }
    }
    void display()
    {
        if(front >= rear){
            for(int i=front ;i<=4;i++)
                cout<<arr[i]<<" ";
            for(int i=0;i<=rear;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
        else
        {
            for(int i=front;i<=rear;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }

};
int main()
{
    CQ obj;
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(5);
    obj.display();
    obj.dequeue();
    obj.dequeue();
    obj.enqueue(6);
    obj.display();

}