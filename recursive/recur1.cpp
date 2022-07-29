#include<iostream>
using namespace std;

int sum(int n1, int n2)
{
    if(n1 > n2)
        return 0;
    else
    {
        return(n1 + sum (n1+1, n2));
    }
}
long fact(int n)
{
    if(n==1)
        return 1;
    else
    {
        return(n * fact(n-1));
    }
} 
int main()
{
    cout<<sum(1,5)<<endl;
    cout<<fact(5);
}

// 1 + (2,10)         2 + (3,10)                3 + (4,10)                      8+  9+  10 + 0 (11,10)
    