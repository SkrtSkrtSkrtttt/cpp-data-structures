//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
#include <vector>

using namespace std;

int search(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;  // Found the target.
        }

        if (nums[left] <= nums[mid]) {
            // Left half is sorted.
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        else {
            // Right half is sorted.
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }

    return -1;  // Target not found in the array.
}

int main() {
    vector<int> arr1 = { 2, 3, 4, 5, 0, 1 };
    int target1 = 0;
    int result1 = search(arr1, target1);
    cout << "Output for arr1: " << result1 << endl;

    vector<int> arr2 = { 2, 4, 5, 0, 1 };
    int target2 = 3;
    int result2 = search(arr2, target2);
    cout << "Output for arr2: " << result2 << endl;

    return 0;
}
