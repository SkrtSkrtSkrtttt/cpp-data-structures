//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack <char> s;
        // iterating string
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                s.push(str[i]);
            }
            else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
            {
                if (s.empty() == 1) // if underflow then unbalanced
                {
                    return false;
                }
                else if (str[i] == ')') // cond for ()
                {
                    char x = s.top();
                    s.pop();
                    if (x != '(')
                    {
                        return false;
                    }
                }
                else if (str[i] == '}') // cond for {}
                {
                    char x = s.top();
                    s.pop();
                    if (x != '{')
                    {
                        return false;
                    }
                }
                else if (str[i] == ']') // cond for []
                {
                    char x = s.top();
                    s.pop();
                    if (x != '[')
                    {
                        return false;
                    }
                }
            }
        }
        if (s.empty() == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};



int main() {
    Solution solution;

    // Example 1
    string input1 = "()";
    cout << "Example 1: " << (solution.isValid(input1) ? "true" : "false") << endl;

    // Example 2
    string input2 = "()[]{}";
    cout << "Example 2: " << (solution.isValid(input2) ? "true" : "false") << endl;

    // Example 3
    string input3 = "(]";
    cout << "Example 3: " << (solution.isValid(input3) ? "true" : "false") << endl;

    // Example 4
    string input4 = "(({}))([]";
    cout << "Example 4: " << (solution.isValid(input4) ? "true" : "false") << endl;

    // Example 5
    string input5 = "(";
    cout << "Example 5: " << (solution.isValid(input5) ? "true" : "false") << endl;

    return 0;
}
