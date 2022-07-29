// CPP program to generate power set in lexicographic order.
#include <bits/stdc++.h>
using namespace std;
 
void printSubSeq(string str, int n, int index = -1,
                    string curr = "")
{
    // base case
    if (index == n)
        return;
 
    if (!curr.empty()) {
        cout << curr << "\n";
    }
 
    for (int i = index + 1; i < n; i++) {
        curr += str[i];
        printSubSeq(str, n, i, curr); 
        // backtracking
        curr = curr.erase(curr.size() - 1);
    }
    return;
}
 
int main()
{
    string str = "abc";
    printSubSeq(str, str.size());
    return 0;
}