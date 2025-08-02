//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
#include <vector>

using namespace std;

vector<int> rowProduct(vector<vector<int>>& nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        int product = 1;
        for (int j = 0; j < nums[i].size(); j++) {
            product *= nums[i][j];
        }
        result.push_back(product);
    }
    return result;
}

int maxProduct(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int maxProduct = nums[0];
    int currentMax = nums[0];
    int currentMin = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(currentMax, currentMin);
        }

        currentMax = max(nums[i], currentMax * nums[i]);
        currentMin = min(nums[i], currentMin * nums[i]);

        maxProduct = max(maxProduct, currentMax);
    }

    return maxProduct;
}

int main() {
    vector<vector<int>> input = { {1, 2, 3}, {2, 2, 2}, {4, 0, 6}, {7, 5, 1}, {2, -2, 1} };

    vector<int> rowResult = rowProduct(input);
    int maxRowProduct = maxProduct(rowResult);

    cout << "Row products: ";
    for (int product : rowResult) {
        cout << product << " ";
    }
    cout << endl;

    cout << "Maximum product: " << maxRowProduct << endl;

    return 0;
}





