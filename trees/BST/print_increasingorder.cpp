#include <stdio.h>
 // ARRAY 

void printIncreasingOrder(int keys[], int low, int high)
{
    if (low > high) {
        return;
    }
    printIncreasingOrder(keys, low*2 + 1, high);  // recur for the left subtree
    printf("%d ", keys[low]);
    printIncreasingOrder(keys, low*2 + 2, high);      // recur for the right subtree
}
 
int main(void)
{
    int keys[] = { 15, 10, 20, 8, 12, 18, 25 };
    int n = sizeof(keys) / sizeof(int);
    printIncreasingOrder(keys, 0, n - 1);
 
    return 0;
}


// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;
 
// // Iterative function 
// void printIncreasingOrder(vector<int> const &keys)
// {
//     int n = keys.size();
//     // base case
//     if (n == 0) {
//         return;
//     }
//     stack<int> s;
//     // start with the root node (the first array element)
//     int r = 0;
//     // push the root node into the stack
//     s.push(r);
//     // run till stack is empty
//     while (!s.empty())
//     {
//         // push the left child of the current node into the stack
//         // and repeat the same for the left child
//         while (r == s.top() && r*2 + 1 < n)
//         {
//             r = r*2 + 1;
//             s.push(r);
//         }
//         // print the last processed node and remove it from the stack
//         r = s.top();
//         s.pop();
//         cout << keys[r] << ' ';
//         // push the right child of the current node into the stack
//         if (r*2 + 2 < n)
//         {
//             r = r*2 + 2;
//             s.push(r);
//         }
//     }
// }
 
// int main()
// {
//     vector<int> keys = { 15, 10, 20, 8, 12, 18, 25 };
 
//     printIncreasingOrder(keys);
 
//     return 0;
// }
