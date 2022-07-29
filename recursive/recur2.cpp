#include<iostream>
using namespace std;


int sumofdigit(int n)
{
    if(n ==0 )
        return 0;
    return( n %10 + sumofdigit(n/10));
}

void factors(int n, int i)
{
    if (i >n)
        return;
    if( n%i == 0)
        cout<<i<<"\t";
    factors(n, i+1);
}

int perfectno(int n,int i)
{
//    6 = 1+2+3+6
    if (i ==n)
        return n;
    if( n%i == 0)
        return(i + perfectno(n, i+1));

    return( 0 + perfectno(n, i+1));
}
int main()
{
    cout<<sumofdigit(123)<<endl;
    factors(6,1);
    int r = perfectno(6,1);
    if(r == 6*2)
        cout<<"PN";
    else
        cout<<"NPN";
}   