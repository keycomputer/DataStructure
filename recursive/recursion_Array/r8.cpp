#include <iostream>
#include <vector>

// Recursive function to generate permutations of an array
void arrayPermutationsRecursive(std::vector<int>& arr, int start, int end) {
    if (start == end) {
        // Base case: Print the current permutation
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        for (int i = start; i <= end; i++) {
            // Swap the elements to generate a new permutation
            std::swap(arr[start], arr[i]);
            // Recursively generate permutations for the remaining elements
            arrayPermutationsRecursive(arr, start + 1, end);
            // Backtrack to restore the original array for the next iteration
            std::swap(arr[start], arr[i]);
        }
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    int n = arr.size();

    std::cout << "Permutations of the array:" << std::endl;
    arrayPermutationsRecursive(arr, 0, n - 1);

    return 0;
}
