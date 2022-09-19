#include <iostream>
using namespace std;
int t;
void abc(int x, int y, int z)
{
if(x < 1 || y < 1 || z < 1)
return;
else
{
t++;
abc(x-2 , y-2 , z-3 );
abc( x-3 , y-1 , z-2);
}
}
int main()
{
t = 0;
abc(10, 20, 30);
cout << t << endl;
return 0;
}