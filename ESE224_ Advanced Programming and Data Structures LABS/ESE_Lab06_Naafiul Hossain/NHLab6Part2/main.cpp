//Naafiul Hossain
//SBU id: 115107623
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::sort(strs.begin(), strs.end()); //START at begin and end 
        int a = strs.size(); //lengnth of our str 
        std::string n = strs[0], m = strs[a - 1], ans = "";
        for (int i = 0; i < n.size() && i < m.size(); i++) { //transvser through our string
            if (n[i] == m[i]) { ans += n[i]; } //if same than add to answer
            else break;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> strings = { "flower","flow","flight" };
    std::vector<std::string> strin = { "dog", "racecar", "car" };

    std::string result1 = solution.longestCommonPrefix(strings);

    Solution solution2;  // Create a new object for the second set of strings
    std::string result2 = solution2.longestCommonPrefix(strin);

    std::cout << "Longest common prefix for strings: " << result1 << std::endl;
    std::cout << "Longest common prefix for strin: " << result2 << std::endl;

    return 0;
}
