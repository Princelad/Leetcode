#include <bits/stdc++.h>
using namespace std;

// Pattern: build answer incrementally, backtrack when constraints fail.
// Example: generate all subsets with optional pruning.
// Time: O(2^n) typical ; Space: O(n) recursion stack + output
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        function<void(int)> dfs = [&](int i) {
            if (i == static_cast<int>(nums.size())) {
                res.push_back(path);
                return;
            }
            dfs(i + 1); // skip
            path.push_back(nums[i]);
            dfs(i + 1); // take
            path.pop_back();
            };
        dfs(0);
        return res;
    }
};
