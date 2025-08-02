//Naafiul Hossain
// SBU ID: 115107623
#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rev(ListNode* h) {
        ListNode* cur = h;
        ListNode* prev = NULL;
        while (cur) {
            ListNode* n = cur->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rev_list1 = rev(l1);
        ListNode* rev_list2 = rev(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        int sum = 0, rem = 0;

        while (true) {
            sum = 0;
            sum += rem;
            if (rev_list1) {
                sum += rev_list1->val;
                rev_list1 = rev_list1->next;
            }
            if (rev_list2) {
                sum += rev_list2->val;
                rev_list2 = rev_list2->next;
            }
            rem = sum / 10;
            sum = sum % 10;
            tmp->next = new ListNode(sum);
            tmp = tmp->next;

            if (!rev_list1 && !rev_list2 && (rem == 0)) break;
        }
        return rev(dummy->next);
    }
};

int main() {
    Solution sol;

    // Test Case 1
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    // Print the result
    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    // Test Case 2
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(4);
    l3->next->next = new ListNode(3);

    ListNode* l4 = new ListNode(5);
    l4->next = new ListNode(6);
    l4->next->next = new ListNode(4);

    ListNode* result2 = sol.addTwoNumbers(l3, l4);

    // Print the result
    while (result2) {
        std::cout << result2->val << " ";
        result2 = result2->next;
    }
    std::cout << std::endl;

    // Test Case 3
    ListNode* l5 = new ListNode(9);
    l5->next = new ListNode(0);
    l5->next->next = new ListNode(8);

    ListNode* l6 = new ListNode(9);
    l6->next = new ListNode(2);

    ListNode* result3 = sol.addTwoNumbers(l5, l6);

    // Print the result
    while (result3) {
        std::cout << result3->val << " ";
        result3 = result3->next;
    }
    std::cout << std::endl;

    return 0;
}

