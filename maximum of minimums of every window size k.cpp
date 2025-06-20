// #include <bits/stdc++.h>
// using namespace std;

// vector<int> maxOfMin(vector<int>& arr, int n) {
//     vector<int> res(n + 1, INT_MIN); // res[i] will hold answer for window size i
//     stack<int> s;

//     // Step 1: Previous Smaller Element (PSE)
//     vector<int> left(n); // left[i] = index of PSE of arr[i]
//     for (int i = 0; i < n; i++) {
//         while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
//         left[i] = s.empty() ? -1 : s.top();
//         s.push(i);
//     }

//     // Step 2: Next Smaller Element (NSE)
//     while (!s.empty()) s.pop(); // clear the stack
//     vector<int> right(n); // right[i] = index of NSE of arr[i]
//     for (int i = n - 1; i >= 0; i--) {
//         while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
//         right[i] = s.empty() ? n : s.top();
//         s.push(i);
//     }

//     // Step 3: Calculate result using lengths
//     for (int i = 0; i < n; i++) {
//         int len = right[i] - left[i] - 1; // max window where arr[i] is min
//         res[len] = max(res[len], arr[i]);
//     }

//     // Step 4: Fill empty values (make it non-increasing)
//     for (int i = n - 1; i >= 1; i--) {
//         res[i] = max(res[i], res[i + 1]);
//     }

//     // Step 5: Prepare final answer (ignore index 0)
//     vector<int> ans(res.begin() + 1, res.end());
//     return ans;
// }

// int main() {
//     vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
//     int n = arr.size();

//     vector<int> result = maxOfMin(arr, n);

//     cout << "Maximum of minimums for every window size:\n";
//     for (int val : result) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfMinNaive(vector<int>& arr, int n) {
    vector<int> res;

    // For every window size from 1 to n
    for (int k = 1; k <= n; k++) {
        int maxOfMin = INT_MIN;

        // Slide the window of size k
        for (int i = 0; i <= n - k; i++) {
            int minInWindow = INT_MAX;

            // Find the minimum in current window of size k
            for (int j = i; j < i + k; j++) {
                minInWindow = min(minInWindow, arr[j]);
            }

            maxOfMin = max(maxOfMin, minInWindow);
        }

        res.push_back(maxOfMin);
    }

    return res;
}

int main() {
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    int n = arr.size();

    vector<int> ans = maxOfMinNaive(arr, n);
    for (int val : ans) {
        cout << val << " ";
    }
    return 0;
}

