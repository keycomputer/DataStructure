#include<iostream>
using namespace std;

int main()
{
    int a[]={1 ,7 ,4 ,3, 4 ,8 ,7}, n=7, k=2;
    int max;

    for(int i=0;i<n;i++)
    {
        if(max < a[i])
            max = a[i];
    }    
    int freq[max]={0};
    for(int i=0;i<n;i++)
    {
        int index = a[i];
        freq[index] +=1;
        if (freq[index ]>=k){
            cout<<index;
            break;
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<a[i]<<"\t"<<freq[a[i]]<<endl;
    // }
}