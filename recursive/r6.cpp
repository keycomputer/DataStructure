    #include <iostream>
using namespace std;

int pow(int n, int p)
{
    if (p==1)
        return n;
    return(n * pow(n,p-1));
}
int main()
{
    cout<<pow(10,2)<<endl;
    cout<<pow(2,3)<<endl;
    return 0;
}