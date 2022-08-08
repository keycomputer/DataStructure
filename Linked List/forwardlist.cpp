#include<iostream>
#include<forward_list>
#include<algorithm>
using namespace std;
bool check(int n)
{
    return n >=100;
}
bool uniquecheck(char ch1, char ch2)
    {
        return ch1 != ch2;
    }
// class value{
//     bool operator() (const int &n)
//     {return n >= 100;}
// };
int main()
{
    // forward_list <int> f1;
    // forward_list <int> f2={11,12,13,14};
    forward_list <int> f3 (10,100);
    // forward_list <int> f4(f2.begin(),f2.end());
    // forward_list <int> f5(move(f2));

    // f3 = f5;
    // // before_begin()
    // // begin(), end(), cbegin(), cend() , cbefore_begin()

    // for(auto i = f3.begin(); i != f3.end(); i++)
    //     cout<<*i;
    // for(auto &i : f3)
    //     cout<<i;
    // cout<<f3.front()<<endl;
    // cout<<f3.max_size();
    // cout<<f3.empty();
    // cout<<endl;

    // f3.insert_after(f3.begin(), 100);
    // for(auto &i : f3)
    //     cout<<i;
    // cout<<endl;
    
    // f3.insert_after(f3.before_begin(), 100);
    // for(auto &i : f3)
    //     cout<<i;
    // cout<<endl;
    // auto it = f3.begin();
    // for(int i=1;i<=3;i++, it++);

    // f3.insert_after(it,200 );
    // //f1.insert_after(f3.end(), 300);
    // f3.push_front(400);
    //  cout<<endl;
    //  for(auto &i : f3)
    //     cout<<i<<"\t";
    // f3.pop_front();
    // f3.erase_after(f3.begin());

    // f3.assign(5,10);
    // cout<<endl;
    //  for(auto &i : f3)
    //     cout<<i<<"\t";
    // f3.assign({1,2,3,4,5,6,7,8});
    // cout<<endl;
    //  for(auto &i : f3)
    //     cout<<i<<"\t";
    // f3.assign(f4.begin(), f4.end());
    // cout<<endl;
    //  for(auto &i : f3)
    //     cout<<i<<"\t";
////////////////////////////////////////////////////////
    // f3.splice_after(f3.before_begin(), f2, f2.before_begin());
    // cout<<endl;
    //  for(auto &i : f3)
    //     cout<<i<<"\t";
    // f3.remove(100);
    // cout<<endl;
    //  for(auto &i : f3)
    //     cout<<i<<"\t";
    // forward_list <int> f3 = {1,2, 10, 100, 2, 100, 3, 100};
    // f3= forward_list<int>({1,2,3,4, 10, 100, 101, 102});
    // f3.remove_if(check);
    // for(auto &i : f3)
    //     cout<<i<<"\t";
    // f3.remove_if([](int n) {return n>=100;});
    // for(auto &i : f3)
    //     cout<<i<<"\t";
    // value obj;
    // f3.remove_if(obj);
    // for(auto &i : f3)
    //     cout<<i<<"\t";
    
    forward_list<int> f5 = {'1',4,2,3,4,1,2,3,5};
    // sort(f5.begin(), f5.end(), greater<char>());
    // forward_list<char> f5 = {'1','1','2','3','4','5','5','6'};
    f5.unique();
    // f5.unique(uniquecheck);
    cout<<endl;
    for(auto &i : f5)
        cout<<i<<"\t";
    f5.merge(f3);
    f5.reverse();

}

