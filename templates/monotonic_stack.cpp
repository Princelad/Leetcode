#include <bits/stdc++.h>
using namespace std;

// Pattern: maintain stack with monotonic property to find next/prev greater/smaller.
// Example: daily temperatures -> next warmer day distances.
// Time: O(n) ; Space: O(n)
class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temps) {
        int n = static_cast<int>(temps.size());
        vector<int> ans(n, 0);
        vector<int> st; // store indices, temps strictly decreasing
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temps[i] > temps[st.back()]) {
                int j = st.back(); st.pop_back();
                ans[j] = i - j;
            }
            st.push_back(i);
        }
        return ans;
    }
};
