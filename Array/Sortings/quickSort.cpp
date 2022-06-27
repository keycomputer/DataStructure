#include<iostream>
using namespace std;
int Partition(int a[],int p,int q)
{

    int x=a[p];
    int i=p,temp;
    for(int j=p+1;j<=q;j++)
    {
        if(a[j]<=x)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i];
    a[i]=x;
    a[p]=temp;

    return i;
}
void Quicksort(int a[],int p,int q)
{
    if(p<q)
    {
        int r=Partition(a,p,q);
        Quicksort(a,p,r-1);
        Quicksort(a,r+1,q);
    }

}
int main()
{
    int n,a[10000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    Quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
       cout<<a[i]<<"\t ";

}