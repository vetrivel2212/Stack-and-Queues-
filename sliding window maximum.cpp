class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices out of this window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove all smaller elements from the back
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);

            // Add max to answer when we hit window size
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
