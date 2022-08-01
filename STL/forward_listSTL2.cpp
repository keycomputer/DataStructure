#include<iostream>
#include<forward_list>
#include<algorithm>
using namespace std;

bool isvlaue(const int &a)
{
    return (a>4) ? true : false;
}
bool isdata(int n1, int n2)
{    return n1 == n2;
}
int main()
{
    forward_list <int> f1 = {1,2,3,4,5,6,4, 6, 4};

    // f1.remove(4);
    // for(auto &a : f1)
    //     cout<<a<<" ";
    // cout<<"\n";

    // f1.remove_if(isvlaue);
    // for(auto &a : f1)
    //     cout<<a<<" ";
    // cout<<"\n";

    // f1.remove_if([] (int a) {return(a>4);});
    // for(auto &a : f1)
    //     cout<<a<<" ";
    // cout<<"\n";
    forward_list <int> f2 = {1,1,2,3,4,4,5,5,5};
    f2.unique(isdata);
    for(auto &a : f2)
        cout<<a<<" ";
    cout<<"\n";

    f1.reverse();
    f1.swap(f2);
    f1.merge(f2);
    // ==
    // <
    !(f1==f2) 
}
