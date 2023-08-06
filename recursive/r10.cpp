#include <iostream>
using namespace std;
long convertBinary(int);
int main()
{
    long biNo;
    int decNo;
    cout<<" Input any decimal number : ";
    cin>>decNo;

    biNo = convertBinary(decNo);
    cout<<"The Binary value "<<biNo;
    return 0;
}
long convertBinary(int decNo)
{
    static long biNo,r,fctor = 1;
    if(decNo != 0)
    {
         r = decNo % 2;
         biNo = biNo + r * fctor;
         fctor = fctor * 10;
         convertBinary(decNo / 2);
    }
    return biNo;
}
