
#include <iostream>
using namespace std;

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
void countSort(int array[], int size, int place) {

  int output[size];
  int count[10]={0};
  int max = 10;


  for (int i = 0; i < max; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[(array[i]/place)%10]++;
  }

  for (int i = 1; i < max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i]/place)%10]-1] = array[i];
    count[(array[i]/place)%10]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
  printArray(array,  size);
}
int maxnum(int arr[], int n)
{
    int max = arr[0];
    for(int i=0;i<n;i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}
void radix(int arr[], int n)
{
    int max = maxnum(arr, n);
    for (int i=1; max/i >=0; i*=10)
        countSort(arr, n, i);
}



int main() {
  int array[] = {1897	,780	,454,	677,	333,	245,	760};
  int n = sizeof(array) / sizeof(array[0]);
  radix(array, n);
  printArray(array, n);
}