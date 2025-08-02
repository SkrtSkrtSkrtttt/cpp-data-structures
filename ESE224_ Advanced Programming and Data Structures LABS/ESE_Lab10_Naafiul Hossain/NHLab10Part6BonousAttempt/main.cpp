//Naafiul Hossain
//SBU ID: 115107623 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthLargestPQ(vector<int>& vec, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : vec) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int jthSmallestPQ(vector<int>& vec, int j) {
    priority_queue<int> maxHeap;

    for (int num : vec) {
        maxHeap.push(num);
        if (maxHeap.size() > j) {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}

int main() {
    vector<int> vector3 = { 989, 2, 3, 7, 9, 5, 7, 7 };
    vector<int> vector4 = { 96, 56, 7, 7, 6, 1, 6, 2 };

    int k;
    cout << "Original vector3: ";
    for (int num : vector3) {
        cout << num << " ";
    }
    cout << "\nInput K for Kth largest: ";
    cin >> k;

    int kthLargest = kthLargestPQ(vector3, k);
    cout << "The " << k << " largest number: " << kthLargest << "\n";

    int j;
    cout << "\nOriginal vector4: ";
    for (int num : vector4) {
        cout << num << " ";
    }
    cout << "\nInput J for Jth smallest: ";
    cin >> j;

    int jthSmallest = jthSmallestPQ(vector4, j);
    cout << "The " << j << " smallest number: " << jthSmallest << "\n";

    return 0;
}