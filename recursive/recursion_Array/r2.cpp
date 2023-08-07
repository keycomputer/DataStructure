
#include<bits/stdc++.h>
using namespace std;
int largest_element(int n, int arr[]){

   if(n==1) return arr[0]; 
   return max(arr[n-1], largest_element(n-1, arr));
}
int main()
{ 
    int arr[] = {10, 5, 8, 14, 7};
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout<<"Largest Element is : "<<largest_element(n, arr); 
    return 0;
}