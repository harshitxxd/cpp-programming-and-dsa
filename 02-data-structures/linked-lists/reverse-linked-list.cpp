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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
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

    Solution sol;
    ListNode* reversed = sol.reverseList(head);

    for (auto x : collectList(reversed)) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
