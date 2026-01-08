#include <bits/stdc++.h>
using namespace std;

// Pattern: 1D DP over index; often rolling array.
// Example: house robber linear.
// Time: O(n) ; Space: O(1)
class Solution {
public:
    int rob(const vector<int>& nums) {
        int take = 0, skip = 0;
        for (int v : nums) {
            int takeNew = skip + v;
            int skipNew = max(skip, take);
            take = takeNew; skip = skipNew;
        }
        return max(take, skip);
    }
};
