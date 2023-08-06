#include <iostream>
using namespace std;

int countofDigits(int n)
{
    if (n == 0)
        return 0;
    return(1 + countofDigits(n/10));
}
int main()
{
    cout<<countofDigits(1234);

    return 0;
}