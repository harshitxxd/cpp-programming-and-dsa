#include <iostream>
using namespace std;

// Time Complexity: O(n)
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int value) {
        val = value;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

void insert(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return NULL;

        Node* curr = head;
        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* next = curr->next;
                Node* child = flatten(curr->child);

                curr->next = child;
                child->prev = curr;
                curr->child = NULL;

                Node* tail = child;
                while (tail->next != NULL) {
                    tail = tail->next;
                }

                tail->next = next;
                if (next != NULL) {
                    next->prev = tail;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insert(head, tail, 1);
    insert(head, tail, 2);
    insert(head, tail, 3);
    insert(head, tail, 4);
    insert(head, tail, 5);
    insert(head, tail, 6);

    Node* childHead = NULL;
    Node* childTail = NULL;
    insert(childHead, childTail, 7);
    insert(childHead, childTail, 8);
    insert(childHead, childTail, 9);
    insert(childHead, childTail, 10);
    head->next->next->child = childHead;

    Node* grandchildHead = NULL;
    Node* grandchildTail = NULL;
    insert(grandchildHead, grandchildTail, 11);
    insert(grandchildHead, grandchildTail, 12);
    childHead->next->child = grandchildHead;

    Solution solution;
    Node* flattened = solution.flatten(head);

    while (flattened != NULL) {
        cout << flattened->val << " ";
        flattened = flattened->next;
    }

    return 0;
}
