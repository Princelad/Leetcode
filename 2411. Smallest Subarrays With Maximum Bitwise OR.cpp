#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> lastPos(32, -1);  // Track rightmost position of each bit

        // Iterate from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Update last position for each bit in nums[i]
            for (int bit = 0; bit < 32; bit++) {
                if (nums[i] & (1 << bit)) {
                    lastPos[bit] = i;
                }
            }

            // Find the farthest position needed to get maximum OR
            int maxPos = i;
            for (int bit = 0; bit < 32; bit++) {
                if (lastPos[bit] != -1) {
                    maxPos = max(maxPos, lastPos[bit]);
                }
            }

            // Length of smallest subarray starting at i
            result[i] = maxPos - i + 1;
        }

        return result;
    }
};