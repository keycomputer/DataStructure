
// Double Ended queue
#include<iostream>
using namespace std;

class DbEqueue
{
    int arr[100];
    int front , rear;
    public:
    DbEqueue()
    {
        front = rear = -1;
    }
    bool isfull()
    {
        return ((front ==0 && rear == 99)  );
    }
    void insertFront(int elem)
    {
        if(isfull() || (front == 0))
        {
            cout<<"Overflow";
        }
        else
        {
            if(front == -1 && rear ==-1)
            {
                front = rear =0;
                arr[front] = elem;
            }
            else if(front != 0)
            {
                arr[--front]= elem;
            }
            
        }
    }
    void insertRear(int elem)
    {
        if(isfull() || (rear == 99))
            cout<<"Overflow ";
        else{
            if(front == -1 && rear ==-1)
            {
                front = rear =0;
                arr[front] = elem;
            }
            else
            {
                rear++;
                arr[rear] = elem;
            }
        }
    }
    void deleteFront()
    {
        if(front == -1 && rear == -1)
            cout<<"Underflow ";
        else{
            cout<<"\nDeleting "<<arr[front];
            if(front == rear)
                front = rear =-1;
            else{
                front++;
            }
        }
    }
    void deleteRear()
    {
        if(front == -1 && rear == -1)
            cout<<"Underflow ";
        else{
            cout<<"\nDeleting "<<arr[rear];
            if(front == rear)
                front = rear =-1;
            else{
                rear--;
            }
        }
    }
    void display()
    {
        for(int i=front ; i<rear ;i++)
            cout<<arr[i]<<"\t";
        cout<<endl;
    }
};

int main()
{
    int opt, opt1;
    DbEqueue obj;
    cout<<"1. input \n2.Output ";
    cin>>opt;
    if(opt== 1)
    {
        while(1)
        {
            cout<<"1. insert rear \n2. delete front\n3. delete rear\n 4. display \n0. Exit";
            cin>>opt1;
            switch (opt1)
            {
                case 1: 
                    int elem;
                    cout<<"Enter element  ";
                    cin>>elem;
                    obj.insertRear(elem);
                    break;
                case 2:
                    obj.deleteFront();
                    break;
                case 3:
                    obj.deleteRear();
                    break;
                case 4:
                    obj.display();
                    break;
                case 0:
                    exit(0);
                default:
                    break;
            }
        }
    }
}