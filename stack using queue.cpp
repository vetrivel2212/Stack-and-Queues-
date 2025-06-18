#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
        // nothing needed here
    }

    void push(int x) {
        int size = q.size();
        q.push(x);

        // Bring all previous elements to the back
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
