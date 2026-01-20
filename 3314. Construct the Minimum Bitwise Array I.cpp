#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size(), i = 0;

        vector<int> ans(n, -1);

        for (int idx = 0; idx < n; ++idx) {
            int num = nums[idx];

            if ((num & 1) == 0) {
                ans[idx] = -1;
                continue;
            }

            int trailingOnes = 0;
            while ((num >> trailingOnes) & 1) ++trailingOnes;

            ans[idx] = num - (1 << (trailingOnes - 1));
        }

        return ans;
    }
};