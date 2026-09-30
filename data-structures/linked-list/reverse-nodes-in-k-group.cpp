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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        while (count < k) {
            if(temp == NULL) return head ;
            temp = temp->next;
            count++;
        }

        ListNode* prevnode = reverseKGroup(temp,k);
        temp = head ; count =  0;
        while (count < k){
        ListNode* next = temp->next;
        temp->next = prevnode;
        prevnode = temp ;
        temp = next;
        count ++;
        }       
        return prevnode;
    }
};

int main() {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    insert(head, tail, 1);
    insert(head, tail, 2);
    insert(head, tail, 3);
    insert(head, tail, 4);
    insert(head, tail, 5);

    Solution solution;
    head = solution.reverseKGroup(head, 2);

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
