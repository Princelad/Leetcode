#include <bits/stdc++.h>
using namespace std;

// Pattern: prefix sums for range queries; difference array for range updates.
// Example: apply range increments then reconstruct array.
// Time: O(n + q) ; Space: O(n)
class Solution {
public:
    vector<int> applyRangeAdds(int n, const vector<array<int, 3>>& queries) {
        // queries: {l, r, delta} inclusive l,r
        vector<int> diff(n + 1, 0);
        for (auto [l, r, d] : queries) {
            diff[l] += d;
            if (r + 1 < n) diff[r + 1] -= d;
        }
        vector<int> res(n, 0);
        int run = 0;
        for (int i = 0; i < n; ++i) {
            run += diff[i];
            res[i] = run;
        }
        return res;
    }
};
