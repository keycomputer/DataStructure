// 1. Linear and 2. Divide n Conquer
// 1. Linear search  
//
#include <iostream>
#include<climits>
using namespace std;
struct Pair
{
    int min, max;
};
struct Pair max_min(int arr[] , int n)
{
    struct Pair p1;
    p1.min = INT_MAX;
    p1.max= INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(p1.min > arr[i])
            p1.min = arr[i];
        if(p1.max < arr[i])
            p1.max = arr[i];
    }
    return p1;
}
int main()
{
    struct Pair minmax;
    int arr[] = {6,3,4,1,5,7,2};
    minmax = max_min(arr,sizeof(arr)/ sizeof(int)-1);
    printf("%d %d", minmax.max, minmax.min);
}

// 2. using divide n conqure algorithm
 
// #include<stdio.h>
// struct Pair
// {
// int min, max;
// };
// struct Pair max_min(int arr[], int i, int j)
// {
//     int mid;
//     struct Pair temp, p1,p2;
//     if(i == j){ 
//         temp.min = temp.max = arr[i];
//     }
//     else if (i == j-1)
//     {
//         if (arr[i] > arr[j])
//         {
//             temp.max = arr[i]; temp.min = arr[j];
//         }
//         else
//         {
//             temp.min = arr[i]; temp.max = arr[j];
//         }
//     }
//     else{
//         mid = (i+j)/2;
//         p1= max_min(arr, i+1, mid);
//         p2 =max_min(arr, mid+1, j );
//         if(p1.min < p2.min)
//             temp.min = p1.min;
//         else
//             temp.min = p2.min;
//         if(p1.max > p2.max)
//             temp.max = p1.max;
//         else
//             temp.max = p2.max;
//     }
//     return temp;
// }

// int main()
// {
//     struct Pair minmax;
//     int arr[] = {6,3,4,1,5,7,2};

//     minmax = max_min(arr, 0, sizeof(arr)/ sizeof(int)-1);
//     printf("%d %d", minmax.max, minmax.min);
// }

//prg2
