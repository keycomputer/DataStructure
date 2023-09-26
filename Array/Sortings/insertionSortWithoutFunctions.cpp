#include <iostream>
using namespace std;
int main()
{
    int arr[] = {6,1,4,9,5,0}, n = 6;
    for(int i=1;i<n;i++)
    {
        int temp = arr[i];  // 1 
        int j = i-1;       //0 
        while(j>=0 && arr[j] > temp)  // j == -1 # arr[j]value is smaller 
        {
            arr[j+1] = arr[j];  // 6 -> right // 6 6 4 9 5 0 
            j--;
        }
        arr[j+1] = temp;          // 1 6 4 9 5 0 
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    return 0;
}