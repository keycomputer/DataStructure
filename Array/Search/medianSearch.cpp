#include "bits/stdc++.h"
using namespace std;
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Returns the correct position of pivot element
int Partition(int arr[], int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);


    int lst = arr[r], i = l, j = l;
    while (j < r) {
        if (arr[j] < lst) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    swap(&arr[i], &arr[r]);
    return i;
}
void MedianUtil(int arr[], int l, int r,
                int k, int& a, int& b)
{
    if (l <= r) {
        int partitionIndex
            = Partition(arr, l, r);
 
        // If partition index = k, then we found the median of odd
        // number element in arr[]
        if (partitionIndex == k) {
            b = arr[partitionIndex];
            if (a != -1)
                return;
        }
 
        // If index = k - 1, then we get a & b as middle element of
        else if (partitionIndex == k - 1) {
            a = arr[partitionIndex];
            if (b != -1)
                return;
        }
        // find the index in first half f the arr[]
        if (partitionIndex >= k)
            return MedianUtil(arr, l,partitionIndex - 1,k, a, b);
         // find the index in second half of the arr[]
        else
            return MedianUtil(arr,
                              partitionIndex + 1,
                              r, k, a, b);
    }
    return;
}
 
int main()
{
    int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans, a = -1, b = -1;
    if (n % 2 == 1) {  // If n is odd
        MedianUtil(arr, 0, n - 1,
                   n / 2, a, b);
        ans = b;
    }
    else {     // If n is even
        MedianUtil(arr, 0, n - 1,
                   n / 2, a, b);
        ans = (a + b) / 2;
    }
    cout << "Median = " << ans;
    return 0;
}