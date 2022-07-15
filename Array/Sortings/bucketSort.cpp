#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// O(n+k)
void bucketSort(int arr[], int n)
{
    vector<int> b[n];
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; 
        b[bi].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
int main()
{
    int arr[] = { 10, 5,7,2,9,11,45};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}