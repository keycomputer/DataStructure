#include <iostream>
using namespace std;


int fibo(int n)
{
    if (n ==0 )
        return 0;
    else if (n==1)
        return 1;
    return(fibo(n-1) + fibo(n-2));
}
void fibonacci(int n1, int n2)
{
    if(n1 > n2)
        return;
    cout<<fibo(n1-1)<<"  ";
    fibonacci(n1+1, n2);
}

int main()
{
    fibonacci(1,10);
}