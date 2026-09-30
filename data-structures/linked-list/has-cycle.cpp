#include <iostream>
using namespace std;

// Time Complexity: O(n)
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

void insert(ListNode*& head, ListNode*& tail, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    insert(head, tail, 3);
    insert(head, tail, 2);
    insert(head, tail, 0);
    insert(head, tail, -4);
    tail->next = head->next;

    Solution sol;
    cout << boolalpha << sol.hasCycle(head) << endl;

    return 0;
}
