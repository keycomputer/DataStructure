

#include <iostream>
using namespace std;

void printarr(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int partition(int arr[], int low, int high) {
    
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i+1];
  arr[i] = arr[high];
  arr[high] = temp;
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int p = partition(arr, low, high);
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
  }
}
int main() {
  int data[] = {8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);;
  quickSort(data, 0, n - 1);
  printarr(data, n);
}