#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, value, cnt;
    Node *next, *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

struct List {
    int size;
    Node *head, *tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};

class LFUCache {
public:
    map<int, Node*> keyNode;
    map<int, List*> freqList;
    int max_cache_size;
    int minFreq;
    int currSize;

    LFUCache(int capacity) {
        max_cache_size = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void updateFreqList(Node *node) {
        int freq = node->cnt;
        freqList[freq]->removeNode(node);

        if (freq == minFreq && freqList[freq]->size == 0) {
            minFreq++;
        }

        node->cnt++;
        if (freqList.find(node->cnt) == freqList.end()) {
            freqList[node->cnt] = new List();
        }

        freqList[node->cnt]->addFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];
        updateFreqList(node);
        return node->value;
    }

    void put(int key, int value) {
        if (max_cache_size == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        } else {
            if (currSize == max_cache_size) {
                List* list = freqList[minFreq];
                Node* toDelete = list->tail->prev;
                keyNode.erase(toDelete->key);
                list->removeNode(toDelete);
                currSize--;
            }

            Node* newNode = new Node(key, value);
            minFreq = 1;

            if (freqList.find(minFreq) == freqList.end()) {
                freqList[minFreq] = new List();
            }

            freqList[minFreq]->addFront(newNode);
            keyNode[key] = newNode;
            currSize++;
        }
    }
};
