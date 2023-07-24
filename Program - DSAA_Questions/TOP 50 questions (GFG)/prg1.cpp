//TOP 50 questions (GFG)
//https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
#include <iostream>
using namespace std;

// Prg 1 

int main()
{
    int n;
    cin>> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if (n==1)
        cout<<0;
    if (arr[0] > arr[1])
        cout<<0;
    if (arr[n-1] >=arr[n-2])
        cout<<n-1;
    
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            cout<< i;
    
    }
       return 0;
}
// Prg2  O(log(n))
int main()
{
    int n;
    cin>> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int s, e, m;
    s=0;
    e = n-1;
    while(s<e)
    {
        m = s +(e-s)/2;
        if (arr[m] > arr[m+1])
            e=m;
        else
            s = m+1;
    }
    cout<<s;
    return 0;
}


