
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,1,2,3,4,5,1,2,3}, n =13, x= 5, count=0;
    int i, j;
    for(i=0, j= n-1; i <= j ; )
    {
        if (count == 2)
            break;
        if(arr[i] == x)
            count++;
        else
            i++;
        if(arr[j]== x)
            count++;
        else
            j--;
    }
    cout<<i<<"\t"<<j;
}