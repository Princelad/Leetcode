#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Count total number of 1's
        int total_ones = 0;
        for (int num : nums) {
            total_ones += num;
        }

        // Edge case: no 1's or all 1's
        if (total_ones == 0 || total_ones == n) return 0;

        // Sliding window approach
        int max_ones_in_window = 0;
        int current_ones = 0;

        // First window
        for (int i = 0; i < total_ones; i++) {
            current_ones += nums[i];
        }
        max_ones_in_window = current_ones;

        // Slide the window circularly
        for (int i = 0; i < n; i++) {
            // Remove the left element (wrapping around)
            current_ones -= nums[i];
            // Add the new right element (wrapping around)
            current_ones += nums[(i + total_ones) % n];
            max_ones_in_window = max(max_ones_in_window, current_ones);
        }

        return total_ones - max_ones_in_window;
    }
};