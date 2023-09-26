
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {6,1,4,9,5,0}, n = 6;
    for(int i = 0;i<n;i++)
    {
        int min = arr[i];
        int pos = i;
        for (int j = i+1;j<n;j++)
        {
            if(min > arr[j])
            {
                min = arr[j]; pos = j;
            }
        }
        swap(arr[i], arr[pos]);
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    return 0;
}