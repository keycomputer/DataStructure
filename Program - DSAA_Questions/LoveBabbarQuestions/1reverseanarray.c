// Reverse an array 
#include <stdio.h>

void reverse(int arr[], int i, int j)
{
    if(i >=j ) 
        return;
    else
    {
        int temp = arr[i];  
        arr[i] = arr[j];
        arr[j] = temp;
        reverse(arr, i+1 , j-1);
    }
}
int main()
{
    int a[] = {1,2,3,4,5}, i;
    reverse(a, 0, sizeof(a)/sizeof(int)-1);
    for(i=0; i<sizeof(a)/sizeof(int);i++)
        printf("%d ", a[i]);
    return 0;
}

