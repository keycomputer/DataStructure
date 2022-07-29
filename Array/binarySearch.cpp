
// O(logn)
// O(1)
// 1 3 6 8 10 15

// 0 5
// mid = 2 -> 6     6 == 12 X
//                 6 > 12 X
// 3 5
// mid = 4 ->10      

// 5 5
// mid  = 5 ---- 15  

// 5 4

#include<iostream>
using namespace  std;

int binarySearch(int arr[], int n, int elem)
{
    int i = 0 , j = n-1;

    while(i <= j)
    {
        int mid = (i+j)/2;
        if(arr[mid]== elem)
            return mid;
        else if (arr[mid] > elem)
            j = mid -1;
        else
            i = mid+1;
    }
    if(i > j)
        return -1;
}
int main()
{
    
}