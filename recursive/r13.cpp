#include <iostream>
using namespace std;

int multiply(int x, int y) {
  if (x == 0 || y == 0)
    return 0;
  if (y > 0)
    return x + multiply(x, y - 1);
  else
    return -x + multiply(x, y + 1);
}

int main()
{
    cout<<multiply(2,3)<<endl;
    cout<<multiply(10,2);
    return 0 ;
}