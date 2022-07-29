#include<iostream>
using namespace std;
int fibo(int i)
{
    if(i==0)
        return 0;
    else if(i==1)
        return 1;
    return(fibo(i-2)+ fibo(i-1));
}
void fibonacci(int n1, int n2)
{
    if (n1==n2)
        return;
    cout<<fibo(n1)<<"\t";
    fibonacci(n1+1, n2);
}
int main()
{
    int n;
    cin>>n;
    fibonacci(0,n);
}