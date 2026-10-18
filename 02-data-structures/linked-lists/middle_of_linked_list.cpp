#include <iostream>
#include <vector>
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

vector<int> collectList(ListNode* head) {
    vector<int> result;
    while (head != NULL) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

int main() {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    insert(head, tail, 1);
    insert(head, tail, 2);
    insert(head, tail, 3);
    insert(head, tail, 4);
    insert(head, tail, 5);
    insert(head, tail, 6);

    Solution sol;
    ListNode* middle = sol.middleNode(head);

    for (auto x : collectList(middle)) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
