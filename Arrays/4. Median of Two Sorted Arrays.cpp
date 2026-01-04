#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the shorter array for O(log(min(n,m))) complexity
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();
        int left = 0, right = n;

        while (left <= right) {
            int cut1 = (left + right) / 2;  // partition point in nums1
            int cut2 = (n + m + 1) / 2 - cut1;  // partition point in nums2

            // Handle edge cases when partition is at boundaries
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right1 = (cut1 == n) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            // Check if we found the correct partition
            if (left1 <= right2 && left2 <= right1) {
                // If total length is even
                if ((n + m) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else {
                    // If total length is odd
                    return max(left1, left2);
                }
            }
            else if (left1 > right2) {
                // cut1 is too far right, move left
                right = cut1 - 1;
            }
            else {
                // cut1 is too far left, move right
                left = cut1 + 1;
            }
        }

        return -1.0;
    }
};