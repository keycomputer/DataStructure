#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[],int n, int i)
{
    if(i>=n/2)
        return;
    swap(arr[i],arr[n-1-i]);
    reverse(arr,n,i+1);
}
void display(int arr[], int n)
{
    if (n == 0)
        return;
    display(arr, n-1);
    cout<<arr[n-1]<<"  ";
}
int main()
{
    int arr[]={1,2,3,4,5};
    reverse(arr, 5, 0);
    display(arr, 5);
    return 0;
}