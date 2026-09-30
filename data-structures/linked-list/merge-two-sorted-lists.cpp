#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n + m)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = (list1 != NULL) ? list1 : list2;
        return dummy.next;
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
    ListNode* list1 = NULL;
    ListNode* tail1 = NULL;
    insert(list1, tail1, 1);
    insert(list1, tail1, 2);
    insert(list1, tail1, 4);

    ListNode* list2 = NULL;
    ListNode* tail2 = NULL;
    insert(list2, tail2, 1);
    insert(list2, tail2, 3);
    insert(list2, tail2, 4);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    for (auto x : collectList(merged)) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
