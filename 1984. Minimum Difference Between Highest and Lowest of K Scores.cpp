#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i + k - 1 < n; ++i) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 9, 4, 1, 6, 5, 10, 0, 4, 2, 7 };
    int k = 2;
    cout << sol.minimumDifference(nums, k) << endl;  // Output: 1
    return 0;
}