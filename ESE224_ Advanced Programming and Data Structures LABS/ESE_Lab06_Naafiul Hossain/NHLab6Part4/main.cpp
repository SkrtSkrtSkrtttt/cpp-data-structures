//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
#include <vector>
//Sliding Window Algorthim 

int maxLengthSubarraySum(std::vector<int>& nums, int k) {
    int left = 0;  //left pointer
    int sum = 0; //sum equal to 0 
    int max_length = 0; //set max length to lowest value 

    for (int right = 0; right < nums.size(); right++) { //start at right pointer and incrment right 
        sum += nums[right]; //keep adding right pointer to the sum 

        while (sum > k) { //as long as the sum is more than k
            sum -= nums[left]; //When sum exceeds k, we need to adjust the subarray by moving the left pointer to the right and subtracting the element at the left position from sum. 
            left++;
        }

        max_length = std::max(max_length, right - left + 1);
        //We keep track of the maximum length of the subarray by calculating right - left + 1 and updating max_length.
    }

    return max_length;
}

int main() {
    // Test case 1
    std::vector<int> nums1 = { 3, 1, 3, 2, 2, 1 };
    int k1 = 4;
    int result1 = maxLengthSubarraySum(nums1, k1);
    std::cout << "Test Case 1: " << result1 << " (Expected Output: 2)" << std::endl;

    // You can add more test cases here to further validate the function.

    return 0;
}