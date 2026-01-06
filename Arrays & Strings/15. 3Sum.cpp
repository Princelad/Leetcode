#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();

        if (size < 3) return result;

        // Sort the array
        sort(nums.begin(), nums.end());

        // Fix one number and find two-sum using two pointers
        for (int i = 0; i < size - 2; i++) {
            // If current number is positive, no triplet can sum to 0
            if (nums[i] > 0) break;

            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Two pointer approach
            int left = i + 1;
            int right = size - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({ nums[i], nums[left], nums[right] });

                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};