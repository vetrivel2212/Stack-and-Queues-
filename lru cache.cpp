#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, value;
    Node *prev, *next;
    
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);  // dummy head
        tail = new Node(0, 0);  // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void insert_after_head(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void delete_node(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        
        Node* node = mp[key];
        delete_node(node);
        insert_after_head(node);
        return node->value;
    }

    void put(int key, int _value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = _value;
            delete_node(node);
            insert_after_head(node);
        } else {
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                mp.erase(lru->key); // Erase LRU's key
                delete_node(lru);
                delete lru; // optional: free memory
            }
            Node* node = new Node(key, _value);
            insert_after_head(node);
            mp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
