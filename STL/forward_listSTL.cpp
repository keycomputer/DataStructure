#include<iostream>
#include<forward_list>
#include<algorithm>
using namespace std;
// Singly Linked List
int main()
{
    // Constructors  
    forward_list <int> f1;
    forward_list <int> f2(10,100);
    forward_list <int> f3(f2.begin(), f2.end());
    forward_list <int> f4(f2);
    forward_list <int> f5( move(f2 ));
    forward_list <int> f6= {1,2,3,4,5,6};

    // f1 = f6;
    // for(auto it= f1.begin() ; it != f1.end() ;it++)
    //         cout<<*it;
    // auto it = f1.begin() ;
    // it++;
    // cout<<*it;
    // f1.insert_after(f1.before_begin(),10);
    // f1.insert_after(f1.begin(),11);
    // f1.insert_after(it, 2, 100);
    // f1.push_front(12);

    // f1.insert_after(it, 14);
    // for(auto it= f1.begin() ; it != f1.end() ;it++)
    //         cout<<*it;
    // cout<<endl;
    // for(auto &a : f1)
    //     cout<<a<<" ";
    // f1.erase_after(f1.begin());
    // for(auto &a : f1){
    //     // a = a+1;
    //     cout<<a<<" ";
    // }
    // begi n end, cbegin  cend, befor_begin, cbefore_begin 

    // empty()  - bool 

    // assign()
    // insert_after
    // push_front(val)

    // erase_after(pt1 v;
    // pop_front()


// swap
// clear
// resize

forward_list <int> f1 = {1,2,3};
forward_list <int> f2 = {4,5,6};
// f1.splice_after(f1.before_begin(), f2);
// for(auto &a : f1)
//     cout<<a<<" ";
auto it = f2.begin();
auto it2 = f2.before_begin();
while(it != f2.end())
{
    it2= it;
    it++;
}
f1.splice_after(it2, f2, f2.before_begin());
cout<<endl;
for(auto &a : f1)
    cout<<a<<" ";

    

}