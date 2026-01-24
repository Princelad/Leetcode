#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        int maxPairSum = 0;

        while (left < right) {
            maxPairSum = max(maxPairSum, nums[left] + nums[right]);
            ++left;
            --right;
        }

        return maxPairSum;
    }
};