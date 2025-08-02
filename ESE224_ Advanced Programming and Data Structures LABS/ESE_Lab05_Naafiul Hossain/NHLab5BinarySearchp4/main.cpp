// Naafiul Hossain
//SBU ID: 115107623

#include <iostream>

int searchInsertPosition(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target is already in the array.
        }

        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return left; // Target not found, return the index where it should be inserted.
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the sorted array: ";
    std::cin >> n;

    int* sortedArray = new int[n]; // Dynamically allocate memory for the array

    std::cout << "Enter the sorted array with distinct integer values: ";
    for (int i = 0; i < n; i++) {
        std::cin >> sortedArray[i];
    }

    int target;
    std::cout << "Enter the integer value to be inserted: ";
    std::cin >> target;

    int insertIndex = searchInsertPosition(sortedArray, n, target);

    std::cout << "The integer " << target << " should be inserted at index " << insertIndex << " to maintain sorted order." << std::endl;

    delete[] sortedArray; // Don't forget to release the dynamically allocated memory

    return 0;
}

