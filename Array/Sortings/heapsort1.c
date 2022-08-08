#include <stdio.h>
void heapsort(int arr[], int n);
void heapify(int arr[], int n, int i);
void swap(int* a, int* b);
int main()
{
    int n, i;
    printf("Enter number of elements to input: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    heapsort(arr, n);
    printf("Elements after sorting\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
void heapsort(int arr[], int n)
{
    int i;
    // Build a max heap
    for(i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // One by one extract elements
    for(i = n-1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void heapify(int arr[], int n, int i)
{
    // initialize largest as root and get left and right nodes
    int largest = i;
    int left_node = 2*i + 1;
    int right_node = 2*i + 2;
    // Check if left node exists and is larger than root. If yes, change it
    if(left_node < n && arr[left_node] > arr[largest])
        largest = left_node;
    // Check if right node exists and is larger than root. If yes, change it
    if(right_node < n && arr[right_node] > arr[largest])
        largest = right_node;
    // change root, if needed
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}