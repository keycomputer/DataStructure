// Linear Search 

#include<iostream>
using namespace std;

void input(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Element in "<<i+1<<"  ";
        cin>>arr[i];
    }
}
bool linearSearch(int arr[], int n, int elem)
{
    for(int i=0;i<n;i++)
        if(arr[i] == elem)
            return true;
    return false;
}
int main(){
    int n;
    cout<<"Enter no of elements";
    cin>>n;
    int arr[n];
    input(arr, n);
    int elem;
    cout<<"Enter element";
    cin>>elem;
    if(linearSearch(arr, n, elem))
        cout<<"Found ";
    else
        cout<<"not found ";
}