#include <bits/stdc++.h>
using namespace std;

// Pattern: 0/1 knapsack; can roll to 1D from right to left.
// Example: max value within capacity.
// Time: O(n * W) ; Space: O(W)
class Solution {
public:
    int knap01(vector<int>& wt, vector<int>& val, int W) {
        vector<int> dp(W + 1, 0);
        for (int i = 0; i < static_cast<int>(wt.size()); ++i) {
            for (int c = W; c >= wt[i]; --c) {
                dp[c] = max(dp[c], dp[c - wt[i]] + val[i]);
            }
        }
        return dp[W];
    }
};
