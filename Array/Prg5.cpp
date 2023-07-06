// 0 1 2 
//[1,1,2,0,1,0,0,2,2,1]
// c1
// c0 
// c2 
// 0 copy 
// 1 copy 
// 2 copy 
#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,1,2,0,1,0,0,2,2,1};
    int c0=0,c1=0,c2=0;
    int i;
    for(i=0;i<10;i++)
    {
        if(arr[i] == 0)
            c0++;
        else if (arr[i] == 1)
            c1++;
        else if (arr[i] == 2)
            c2++;
    }
    for(i = 0;i<c0 ;i ++)
        arr[i] = 0;
    for ( ; i<c0+c1 ;i++ )
        arr[i] = 1;
    for( ; i<c0+c1+c2 ;i++)
        arr[i] = 2;
    for(i=0;i<10;i++)
        cout<<arr[i]<<"  ";

    return 0;
}