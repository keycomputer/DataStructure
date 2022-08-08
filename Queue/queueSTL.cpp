// constructing queues
#include <iostream>       // std::cout
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue
using namespace std;
int main ()
{
  deque<int> mydeck (3,100);        // deque with 3 elements
  list<int> mylist (2,200);         // list with 2 elements

  queue<int> first;                 // empty queue
  queue<int> second (mydeck);       // queue initialized to copy of deque

  queue<int,std::list<int> > third; // empty queue with list as underlying container
  queue<int,std::list<int> > fourth (mylist);

  vector<int> v1= {1,2,3,4};
  queue <int, vector<int>> fifth;
  queue<int,vector<int>> six(v1);




  cout << "size of first: " << first.size() << '\n';
  cout << "size of second: " << second.size() << '\n';
  cout << "size of third: " << third.size() << '\n';
  cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}