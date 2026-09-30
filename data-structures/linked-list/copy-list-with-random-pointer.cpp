#include <iostream>
#include <unordered_map>
using namespace std;

// Time Complexity: O(n)
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void insert(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> m;
        Node* newhead = new Node(head->val);
        Node* oldtemp = head->next;
        Node* newtemp = newhead;
        m[head] = newhead;

        while (oldtemp != NULL) {
            Node* copynode = new Node(oldtemp->val);
            m[oldtemp] = copynode;
            newtemp->next = copynode;
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        oldtemp = head;
        newtemp = newhead;
        while (oldtemp != NULL) {
            newtemp->random = m[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        return newhead;
    }
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insert(head, tail, 7);
    insert(head, tail, 13);
    insert(head, tail, 11);
    insert(head, tail, 10);
    insert(head, tail, 1);

    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    Solution solution;
    Node* copied = solution.copyRandomList(head);

    while (copied) {
        cout << copied->val << " ";
        copied = copied->next;
    }

    return 0;
}
