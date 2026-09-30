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
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
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
    ListNode* cycleStart = sol.detectCycle(head);

    if (cycleStart == NULL) {
        cout << "No cycle" << endl;
    } else {
        cout << "Cycle begins at node with value: " << cycleStart->val << endl;
    }

    return 0;
}
