//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {

    }

    void push(int x) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack* obj = new MyStack();

    // Test case: ["MyStack","push","push","top","pop","empty"]
    cout << "Testing the given test case:\n";
    obj->push(1);
    obj->push(2);
    cout << "Top: " << obj->top() << endl; // Expected output: 2
    cout << "Pop: " << obj->pop() << endl; // Expected output: 2
    cout << "Is empty: " << (obj->empty() ? "true" : "false") << endl; // Expected output: false

    delete obj;
    return 0;
}
