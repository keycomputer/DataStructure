#include<iostream>
using namespace std;
 /*
 Original array: 79 1 2 2 109 32 56 170 109 1 56 
Elements which have at-least two greater elements: 79 1 2 2 32 56 1 56 


79 -> check with rest of the array -> counter is greater than 2  
1 -> check with rest of the array -> 
...... 170 -> no value is greater than 170  
109 only  one value is greater  


 */
void find_greater_elements(int nums[], int n)
{
    cout << "\nElements which have at-least two greater elements: ";
    for (int i=0; i<n; i++)
    {
        int ctr = 0;
        for (int j=0; j<n; j++)
            if (nums[j] > nums[i])
                ctr++;
 
        if (ctr >= 2)
            cout << nums[i] << " ";
    }
}
 

int main()
{
    int nums[] = {79, 1, 2, 2, 109, 32, 56, 170, 109, 1, 56};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << "Original array: ";
    for (int i=0; i < n; i++) 
    cout << nums[i] <<" ";
   find_greater_elements(nums, n);
    return 0;
}
