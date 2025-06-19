class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> pse;
        int n = heights.size();

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if (st.empty()) pse.push_back(-1);
            else pse.push_back(st.top());

            st.push(i);
        }

        while (!st.empty()) st.pop();

        vector<int> nse(n);

        // Next Smaller Element (Right to Left)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty()) nse[i]=n;
            else nse[i]=st.top();

            st.push(i);
        }

        int area = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int currArea = heights[i] * width;
            area = max(area, currArea);
        }

        return area;
    }
};
