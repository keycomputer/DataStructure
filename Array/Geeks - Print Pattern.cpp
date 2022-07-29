// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<int> pattern(int N){
        // code here
        vector<int> v1;
        int temp = N ;
        while(1)
        {
            v1.push_back(temp);
            if(temp <=0)
            
                temp = temp + 5;
            
            else
                temp = temp -5;
            
            if(temp == N)
                break;
            
        }
        return v1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends