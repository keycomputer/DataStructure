#include <iostream>

using namespace std;
void oddeven(int arr[], int even[], int odd[] , int n)
{
    int i, j=0, k=0;
    for(i=0;i<n;i++)
    {
        if(arr[i] % 2 == 0 )
        {
            even[j] = arr[i];
            j++;
        }
        else
        {
            odd[k] = arr[i];
            k++;
        }
    }
    for(i=0;i<j;i++)
        cout<<even[i]<<" ";
    cout<<endl;
    for(i=0;i<k;i++)
        cout<<odd[i]<<"  ";
}
int main()
{
    int arr[] = {6,23,4,1,8,6,7,9};
    int n=8;
    int earr[n], odarr[n];
    
    oddeven(arr, earr, odarr , n); 
    
    return 0;
}
