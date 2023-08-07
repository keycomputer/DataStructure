#include <bits/stdc++.h>
using namespace std;

int linearsearch(int arr[], int size, int key)
{
    if (size == 0) 
        return -1;
    else if (arr[size - 1] == key)
        return size - 1;
    return linearsearch(arr, size - 1, key);
}
int main()
{
    int arr[] = { 67,2,5,4,5,7 };
    int key = 4;
    int ans = linearsearch(arr,6, key);
    if (ans == -1) 
        cout << "The element is not found.";
    else 
        cout << "The element is found at "<< ans << " index.";
    return 0;
}