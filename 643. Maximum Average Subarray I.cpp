#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        const int n = nums.size();

        long long windowSum = accumulate(nums.begin(), nums.begin() + k, 0LL);
        double maxAvg = static_cast<double>(windowSum) / k;

        for (int right = k; right < n; ++right) {
            windowSum += nums[right];
            windowSum -= nums[right - k];
            maxAvg = max(maxAvg, static_cast<double>(windowSum) / k);
        }

        return maxAvg;
    }
};