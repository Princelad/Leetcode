#include <bits/stdc++.h>
using namespace std;

// Pattern: maintain two indices that move toward each other or in tandem.
// Example: sorted array; find pair sum equals target.
// Time: O(n) ; Space: O(1)
class Solution {
public:
    pair<int, int> twoSumSorted(const vector<int>& nums, int target) {
        int l = 0, r = static_cast<int>(nums.size()) - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) return { l, r };
            if (sum < target) ++l; else --r;
        }
        return { -1, -1 }; // not found
    }
};
