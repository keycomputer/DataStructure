#include <iostream>
#include <vector>

// Recursive binary search function
int binarySearchRecursive(const std::vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; // Element not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Element found at index mid
    } else if (arr[mid] > target) {
        return binarySearchRecursive(arr, target, left, mid - 1); // Search left half
    } else {
        return binarySearchRecursive(arr, target, mid + 1, right); // Search right half
    }
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int target = 7;

    int result = binarySearchRecursive(arr, target, 0, arr.size() - 1);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
