#include <iostream>
using namespace std;

int primeNo(int n, int i=2)
{
    if ( n == i )
        return 1;
    
    if (n % i == 0)
        return 0;
    
    return(primeNo(n, i+1));
}
int main()
{
    if(primeNo(5) == 1)
        cout<<"Prime No ";
    else
        cout<<"Not Prime No ";
}
