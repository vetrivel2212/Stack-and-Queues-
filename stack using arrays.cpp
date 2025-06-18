#include <bits/stdc++.h>
using namespace std;

int N = 10;
int stk[10];  // renamed from stack to stk
int top = -1;

void push(int x) {
    if (top == N - 1) {
        cout << "Overflow" << endl;
    } else {
        stk[++top] = x;
    }
}

void pop() {
    if (top == -1) {
        cout << "Underflow" << endl;
    } else {
        top--;
    }
}

void top_el() {
    if (top == -1) {
        cout << "Underflow" << endl;
    } else {
        cout << stk[top] << endl;
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    top_el();  // prints 3
    pop();
    top_el();  // prints 2
}
