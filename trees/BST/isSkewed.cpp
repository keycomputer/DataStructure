//Determine whether a BST is skewed from its preorder traversal

// Input:  Preorder traversal of BST: [15, 30, 25, 18, 20]
// Output: BST is skewed
#include <iostream>
#include <limits.h>
using namespace std;
int isSkewedBST(int pre[], int n)
{
    int min = INT_MIN, max = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (pre[i] >= min && pre[i] <= max)
        {
            if (pre[i] > pre[i-1]) {
                min = pre[i-1] + 1;
            }
            else {
                max = pre[i-1] - 1;
            }
        }
        else {
            return 0;
        }
    } 
    return 1;
}
 
int main(void)
{
    int pre[] = { 15, 30, 25, 18, 20 };
    int n = sizeof(pre) / sizeof(pre[0]);
 
    int isSkewed = isSkewedBST(pre, n);
    if (isSkewed) {
        printf("BST is skewed");
    }
    else {
        printf("BST is not skewed");
    }
 
    return 0;
}

// ===========================================================
// #include<iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
 
// // Function to determine whether the given preorder traversal of a
// // binary tree represents a skewed BST
// bool isSkewedBST(vector<int> &pre)
// {
//     // get the size of the preorder sequence
//     int n = pre.size();
 
//     // base case: if BST has two or fewer nodes
//     if (n <= 2) {
//         return 1;
//     }
 
//     // initialize `min_so_far` and `max_so_far` with the last two elements
//     // in the preorder sequence
//     int min_so_far = min(pre[n-1], pre[n-2]);
//     int max_so_far = max(pre[n-1], pre[n-2]);
 
//     // start from the third element from the end of the preorder sequence
//     for (int i = n - 3; i >= 0; i--)
//     {
//         // check if the current element is in a valid range and update
//         // `min_so_far` & `max_so_far` for the next iteration of the loop
//         if (pre[i] < min_so_far) {
//             min_so_far = pre[i];
//         }
//         else if (pre[i] > max_so_far) {
//             max_so_far = pre[i];
//         }
//         else {
//             return false;
//         }
//     }
 
//     return true;
// }
 
// int main()
// {
//     vector<int> pre = { 15, 30, 25, 18, 20 };
//     bool isSkewed = isSkewedBST(pre);
//     if (isSkewed) {
//         cout << "BST is skewed";
//     }
//     else {
//         cout << "BST is not skewed";
//     }
 
//     return 0;
// }