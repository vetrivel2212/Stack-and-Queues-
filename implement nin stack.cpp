class MinStack {
public:
    stack<long long> st;   // Use long long to handle overflow
    long long mini;

    MinStack() {
        // Initially nothing in the stack
    }

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);  // Push normal value
        } else {
            if (val < mini) {
                // Encode new value and push
                long long encoded = 2LL * val - mini;
                st.push(encoded);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if (topVal < mini) {
            // Decode previous minimum
            mini = 2LL * mini - topVal;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long topVal = st.top();

        if (topVal < mini) {
            // It's an encoded value, so return the actual minimum
            return mini;
        } else {
            return topVal;
        }
    }

    int getMin() {
        return mini;
    }
};
