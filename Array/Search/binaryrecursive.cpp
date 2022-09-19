#include<iostream>
using namespace std;

int BS(int arr[], int l , int h, int elem)
{
    if(l>h)
        return -1;
    int m = (l+h)/2;
    if(arr[m]== elem)
        return m;
    else if (arr[m] > elem)
        return (BS(arr, l, m-1, elem));
    else
        return (BS(arr, m+1, h, elem));
    
}
int main()
{
    int arr[] = {5,6,12,89,100}, n= 5;
    int r = BS(arr, 0, n-1, 6);
    if( r!= -1)
        cout<<r;
    else
        cout<<"Not Found ";
}