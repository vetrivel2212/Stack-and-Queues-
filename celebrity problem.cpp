/*
You are given a matrix M of size n x n where M[i][j] = 1 means person i knows person j, and M[i][j] = 0 means person i does not know person j. A celebrity is defined as:

Everyone knows the celebrity.

The celebrity knows no one.

You need to find if a celebrity exists, and if so, return their index; otherwise, return -1.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to find the celebrity (if exists)
int findCelebrity(vector<vector<int>>& M, int n) {
    int top = 0, bottom = n - 1;

    // Step 1: Eliminate candidates using two pointers
    while (top < bottom) {
        if (M[top][bottom] == 1) {
            // top knows bottom → top can't be celeb
            top++;
        } else {
            // top doesn't know bottom → bottom can't be celeb
            bottom--;
        }
    }

    // Potential celebrity
    int cand = top;

    // Step 2: Final verification
    for (int i = 0; i < n; i++) {
        if (i == cand) continue;

        // Celebrity shouldn't know anyone
        if (M[cand][i] == 1)
            return -1;

        // Everyone should know celebrity
        if (M[i][cand] == 0)
            return -1;
    }

    return cand;
}

// Test function
int main() {
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}, // Person 2 is celebrity
        {0, 0, 1, 0}
    };

    int n = M.size();
    int celeb = findCelebrity(M, n);

    if (celeb == -1)
        cout << "No celebrity found" << endl;
    else
        cout << "Celebrity is person: " << celeb << endl;

    return 0;
}
