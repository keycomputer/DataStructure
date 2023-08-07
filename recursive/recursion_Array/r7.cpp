#include <iostream>

// Recursive function to print elements of an array in reverse order
void printArrayReverseRecursive(int arr[], int n) {
    if (n <= 0) {
        return;
    } else {
        std::cout << arr[n - 1] << " ";
        printArrayReverseRecursive(arr, n - 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array in reverse order: ";
    printArrayReverseRecursive(arr, n);
    std::cout << std::endl;

    return 0;
}