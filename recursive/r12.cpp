#include <iostream>
using namespace std;
int gcd(int x, int y) {
  if (x == 0)
    return y;
  if (y == 0)
    return x;
  return gcd(y, x % y);
}
int main()
{
    cout<<gcd(14,7);
    return 0;
}