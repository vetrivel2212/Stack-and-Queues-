#include<iostream>
using namespace std;

int Queue[10];
int N = 10;
int front = -1;
int back = -1;

void push(int x) {
    if(back == N-1) cout << "Overflow" << endl;
    else if(front == -1 && back == -1) {
        front = 0;
        back = 0;
        Queue[back] = x;
    }
    else {
        Queue[++back] = x;
    }
}

void pop() {
    if(front == -1 && back == -1) {
        cout << "Underflow" << endl;
    }
    else if(front == back) {
        front = -1;
        back = -1;
    }
    else {
        front++;
    }
}

void fornt_el() {
    if(front == -1 && back == -1) {
        cout << "Underflow" << endl;
    }
    else {
        cout << Queue[front] << endl;
    }
}

void back_el() {
    if(front == -1 && back == -1) {
        cout << "Underflow" << endl;
    }
    else {
        cout << Queue[back] << endl;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    fornt_el(); // 10
    back_el();  // 30
    pop();      // remove 10
    fornt_el(); // 20
    pop();      // remove 20
    pop();      // remove 30
    pop();      // Underflow
}
