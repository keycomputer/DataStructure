#include<iostream>
#include<vector>

using namespace std;

int main()
{
    // vector <int > v1;
    // vector <int> v2(10); 
    // vector <int> v3 (3,100);
    // vector <int> v4 (v2.begin(), v2.end());
    // vector <int> v5 (v2);

    // v2 = v3;
    // v3 = vector<int>();

    // for(vector<int>::iterator it= v2.begin(); it != v2.end(); it++)
    //     cout<<*it<<"\t";
    // cout<<endl;
    // for(auto it= v2.begin(); it != v2.end(); it++)
    //     cout<<*it<<"\t";
    // auto i = "abc";
    // cout<<i;
    // cout<<v2.size()<<endl;
    // cout<<v2.max_size()<<endl;
    // cout<<v2.capacity()<<endl;
    // v2.resize(10);
    // cout<<v2.size()<<endl;
    // cout<<v2.max_size()<<endl;
    // cout<<v2.capacity()<<endl;
    // v2.shrink_to_fit();
    // v2.resize(2);
    // v2.reserve(5);
    // cout<<v2.size()<<endl;
    // cout<<v2.max_size()<<endl;
    // cout<<v2.capacity()<<endl;
    

    vector <int> v1 = {1,2,3,4,5};
    for(int i =0;i<v1.size();i++)
        cout<<v1.at(i);  // cout<<v1[i];

    cout<<v1.front()<<"\t";
    cout<<v1.back()<<"\n";

    int *p = v1.data();
    *p = 100;
    *(p+1 ) = 200;
    for(int i =0;i<v1.size();i++)
        cout<<v1.at(i);  // cout<<v1[i];
    v1.assign(v1.begin(), v1.begin()+3);
    v1.assign(5,100);
    int arr[] ={10,20,30,40};
    v1.assign(arr, arr+2);
    v1.push_back(100);
    v1.pop_back();
    v1.insert(v1.begin(), 111);
    v1.insert(v1.begin()+3, v2.begin(), v2.end());
    v1.erase(v1.begin());
    v1.erase(v1.begin()+2, v1.end());
    v1.swap(v2);
    v1.clear();
    vector<int> :: reverse_iterator it = v1.rbegin();
    vector<int> :: const_iterator it2 = v1.cbegin();
    vector<int> :: const_reverse_iterator it = v1.crbegin();
    
    
}