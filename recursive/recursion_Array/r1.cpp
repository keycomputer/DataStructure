// C++ Program to print
// an Array using Recursion

#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int size)
{
	if (size == 0) 
		return;
	print_array(arr, size-1);
	cout << arr[size-1] << " ";

}

// Driver code
int main()
{

	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	print_array(arr, n);
	return 0;
}

