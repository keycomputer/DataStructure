#include <iostream>
using namespace std;

void print(int n)
{
    if (n<1)
        return;
    print(n-1);
    cout<<n<<"  ";
}
int main()
{
    print(50);
    return 0;
}