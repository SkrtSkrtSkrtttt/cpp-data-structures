//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted at given index
void maxHeapify(vector<int>& vec, int n, int root) {
    int largest = root; // Initialize largest as root
    int left = 2 * root + 1; // left child
    int right = 2 * root + 2; // right child

    // If left child is larger than root
    if (left < n && vec[left] > vec[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && vec[right] > vec[largest])
        largest = right;

    // If largest is not root
    if (largest != root) {
        swap(vec[root], vec[largest]);

        // Recursively heapify the affected sub-tree
        maxHeapify(vec, n, largest);
    }
}

// Main function to do heap sort
void maxHeapSort(vector<int>& vec, int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(vec, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(vec[0], vec[i]); // Move current root to end
        maxHeapify(vec, i, 0); // call max heapify on the reduced heap
    }
}

// Function to print the top k largest numbers in ascending order
void printTopKLargest(vector<int>& vec, int n, int k) {
    maxHeapSort(vec, n); // First, sort the entire array using max heap sort

    cout << "Top " << k << " largest numbers: ";
    for (int i = n - 1; i >= max(0, n - k); i--) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    int length, lower_bound, upper_bound;

    // Input length, lower bound, and upper bound
    cout << "Input length, lower bound, and upper bound: ";
    cin >> length >> lower_bound >> upper_bound;

    // Generate a vector of random numbers within the specified range
    vector<int> vec(length);
    for (int i = 0; i < length; i++) {
        vec[i] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    }

    // Display the original vector
    cout << "Original Vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    int k;
    // Input K for the top K largest
    cout << "Input K for the top K largest: ";
    cin >> k;

    printTopKLargest(vec, length, k);

    return 0;
}

