#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class node {
    public:
        int key, val;
        node* prev;
        node* next;

        node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
    };

    node* head;
    node* tail;
    unordered_map<int, node*> m;
    int limit;

    // Time Complexity: O(1)
    void addnode(node* newnode) {
        node* oldnext = head->next;
        head->next = newnode;
        oldnext->prev = newnode;
        newnode->next = oldnext;
        newnode->prev = head;
    }

    // Time Complexity: O(1)
    void delnode(node* oldnode) {
        node* oldprev = oldnode->prev;
        node* oldnext = oldnode->next;
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    // Time Complexity: O(1)
    explicit LRUCache(int capacity)
        : head(new node(-1, -1)), tail(new node(-1, -1)), limit(capacity) {
        head->next = tail;
        tail->prev = head;
    }

    LRUCache(const LRUCache&) = delete;
    LRUCache& operator=(const LRUCache&) = delete;

    // Time Complexity: O(1) average
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }

        node* ansnode = it->second;
        int ans = ansnode->val;
        delnode(ansnode);
        addnode(ansnode);
        return ans;
    }

    // Time Complexity: O(1) average
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            node* oldnode = it->second;
            delnode(oldnode);
            m.erase(it);
            delete oldnode;
        }

        if (static_cast<int>(m.size()) == limit) {
            node* lru = tail->prev;
            delnode(lru);
            m.erase(lru->key);
            delete lru;
        }

        node* newnode = new node(key, value);
        addnode(newnode);
        m[key] = newnode;
    }

    ~LRUCache() {
        node* current = head;
        while (current != NULL) {
            node* nextnode = current->next;
            delete current;
            current = nextnode;
        }
    }
};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    cout << lRUCache.get(1) << '\n';
    lRUCache.put(3, 3);
    cout << lRUCache.get(2) << '\n';
    lRUCache.put(4, 4);
    cout << lRUCache.get(1) << '\n';
    cout << lRUCache.get(3) << '\n';
    cout << lRUCache.get(4) << '\n';
    return 0;
}
