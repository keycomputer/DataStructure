#include <iostream>
using namespace std;

void sum(int n1, int n2, int &sume, int &sumo)
{
    if(n1 > n2)
        return;
    if(n1 % 2==0)
        sume+=n1;
    else
        sumo+=n1;
    sum(n1+1, n2, sume, sumo);
}
int main()
{
    int sume=0, sumo=0;
    sum(1,10, sume, sumo);
    cout<<sume<<endl;
    cout<<sumo;
    return 0;
}