class Solution {
public:
    vector<int> nearestSmallerElement(vector<int>& arr) {
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < arr.size(); ++i) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            if (st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());

            st.push(arr[i]);
        }

        return ans;
    }
};
