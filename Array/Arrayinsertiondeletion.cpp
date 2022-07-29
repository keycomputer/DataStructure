#include<iostream>
using namespace std;
///////////////////////INSERTION /////////////////////////////////
void display(int arr[], int n)
{
    for(int i= 0;i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}
void insertatbegin(int arr[], int &n, int elem)
{
// ||||  99  100 200 300 400 500
    if (n == 100 )
    {
        cout<<"OverFlow \n";
        return;
    }
    for(int i =n-1; i>=0 ;i--)
        arr[i+1] = arr[i];
    arr[0] = elem;
    n++;
}
void insertatend(int arr[], int &n, int elem )
{
    // ||||  99  100 200 300 400 500 
    if (n == 100 )
    {
        cout<<"OverFlow \n";
        return;
    }
    arr[n] = elem;
    n++;
}
void insertatpos(int arr[], int &n, int pos, int elem)
{
    if (n == 100 )
    {
        cout<<"OverFlow \n";
        return;
    }
    for(int i = n-1;i>=pos-1 ;i-- )
        arr[i+1] = arr[i];
    arr[pos-1]= elem;
    n++;
}
void insertinSorted(int arr[], int &n, int elem )
{
    int j = n-1;
    while(j >= 0 && arr[j]> elem)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = elem;
    n++;

}
void deletebegin(int arr[], int &n )
{
    if (n == 0)
        cout<<"Empty Array ";
    else{
        cout<<"Deleting "<<arr[0]<<endl;
        for(int i =0; i<n; i++)
            arr[i] = arr[i+1];
        n--;
    }
}
void deleteend(int arr[], int &n)
{
    if (n==0)
        cout<<"Array is Empty ";
    else{
        cout<<"Deleting "<<arr[n-1]<<endl;
        n--;
    }
}
void deletepos(int arr[], int &n, int pos)
{
    if (n==0)
        cout<<"Array is Empty ";
    else{
        if (pos > n )
            cout<<"Invalid pos \n";
        else{
            for(int i=pos-1; i<n-1;i++)
                arr[i] = arr[i+1];
            n--;
        }
    }
}
void deletevalue(int arr[], int &n, int elem)
{
    if (n==0)
        cout<<"Array is Empty ";
    else
    {
        for(int i =0;i<n;)
        {
            if(arr[i] == elem)
            {
                // deletepos(arr, n, i+1);
                for(int j=i; j<n ;j++)
                {
                    arr[j] = arr[j+1];
                }
                n--;
            }
            else
                i++;
        }
    }
}

int main()
{
    int arr[100], n =0;
    // insertatbegin(arr,n, 100);
    // insertatbegin(arr,n, 200);
    // insertatend(arr,n, 300);
    // insertatend(arr,n, 400);
    
    // display(arr, n);
    // insertatpos(arr, n,3, 250);
    insertinSorted(arr, n, 10);
    insertinSorted(arr, n, 5);
    insertinSorted(arr, n, 5);
    
    insertinSorted(arr, n, 7);
    // deleteend(arr, n);
    // display(arr, n);

    // deletebegin(arr,n);
    // display(arr, n);

    // deletepos(arr, n , 2);
    deletevalue(arr,n, 5);
    display(arr, n);
}