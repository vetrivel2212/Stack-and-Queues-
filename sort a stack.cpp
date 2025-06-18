#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    st.push(5);
    st.push(1);
    st.push(3);
    st.push(2);
    st.push(6);

    stack<int> temp;

    while (!st.empty()) {
        int x = st.top();
        st.pop();

        while (!temp.empty() && x < temp.top()) {
            st.push(temp.top());
            temp.pop();
        }
        temp.push(x);
    }

    // Now temp has the sorted elements (ascending, smallest on top)
    // Let's print it:
    cout << "Sorted Stack (top to bottom): ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
