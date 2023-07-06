#include<iostream>
using namespace std;
 
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void EvenOdd(int nums[], int size)
{
    int left_num = 0, right_num = size-1;
    while (left_num < right_num)
    {
         while (nums[left_num]%2 == 0 && left_num < right_num)
            left_num++;
 
        while (nums[right_num]%2 == 1 && left_num < right_num)
            right_num--;
 
        if (left_num < right_num)
        {
            swap(&nums[left_num], &nums[right_num]);
            left_num++;
            right_num--;
        }
    }
}
 
int main()
{
    int nums[] = {10, 15, 23, 14, 55, 60, 74, 89, 100};
    int n = sizeof(nums)/sizeof(nums[0]);
   	cout << "Original array: ";
    for (int i=0; i < n; i++) 
    cout << nums[i] <<" ";
    EvenOdd(nums, n);
 
    printf("\nArray after divided: ");
      for (int i=0; i < n; i++) 
      cout << nums[i] <<" ";
        return 0;
     }
