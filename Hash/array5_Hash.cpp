// Count distinct elements in every window of size k
#include <iostream>
#include <unordered_map>
using namespace std;

void countDistinct(int arr[], int K, int N)
{
    unordered_map<int, int> hm;
    int dist_count = 0;
    for (int i = 0; i < K; i++) {
        if (hm[arr[i]] == 0) {
            dist_count++;
        }
        hm[arr[i]] += 1;
    }
    cout << dist_count << endl;
    for (int i = K; i < N; i++) {
        if (hm[arr[i - K]] == 1) {
            dist_count--;
        }
        hm[arr[i - K]] -= 1;
        if (hm[arr[i]] == 0) {
            dist_count++;
        }
        hm[arr[i]] += 1;
        cout << dist_count << endl;
    }
}
int main()
{
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 4;
    countDistinct(arr, K, N);
    return 0;
}