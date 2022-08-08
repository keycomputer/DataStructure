#include <iostream>
#include <set>
using namespace std;
bool fncomp (int lhs, int rhs) {return lhs>rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  set<int> first;                           // empty set of ints

  int myints[]= {100,20,330,40,50};
  set<int> second (myints,myints+5);        // range
//   cout<<second.size();   
  for(auto it= second.begin() ; it!=second.end(); it++)
    cout<<*it;  
  set<int> third (second);                  // a copy of second

  set<int> fourth (second.begin(), second.end());  // iterator ctor.

  set<int,classcomp> fifth;                 // class as Compare

  bool(*fn_pt)(int,int) = fncomp;
  set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
  sixth.insert(sixth.begin(), 10);
  sixth.insert(sixth.begin(), 5);
  sixth.insert(sixth.begin(), 15);
  
  for(auto it= sixth.begin() ; it!=sixth.end(); it++)
    cout<<*it;
  
  return 0;
}