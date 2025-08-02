//Naafiul Hossain
//SBU ID: 115017623
#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    int front() {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    bool empty() {
        return s1.empty();
    }
};
int main() {
    MyQueue* obj = new MyQueue();

    // Test operations
    obj->push(1);
    obj->push(2);

    int param_3 = obj->front();
    cout << "Front: " << param_3 << endl;

    int param_4 = obj->pop();
    cout << "Pop: " << param_4 << endl;

    bool param_5 = obj->empty();
    cout << "Empty: " << (param_5 ? "true" : "false") << endl;

    delete obj;  // Don't forget to free the allocated memory

    return 0;
}

