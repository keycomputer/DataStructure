#include <iostream>
using namespace std;

int sumofDigits(int n)
{
    if (n == 0)
        return 0;
    return(n %10 + sumofDigits(n/10));
}
int main()
{
    cout<<sumofDigits(1234);

    return 0;
}