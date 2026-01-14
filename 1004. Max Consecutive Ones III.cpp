/*
1004. Max Consecutive Ones III

Problem: Given a binary array nums and an integer k, return the maximum number
of consecutive 1's in the array if you can flip at most k 0's.

Approach: Sliding Window
- Use two pointers (left and right) to maintain a window
- Count the number of zeros in the current window
- If zeros exceed k, shrink the window from the left
- Track the maximum window size

Time Complexity: O(n) - each element visited at most twice
Space Complexity: O(1) - only using a few variables
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;      // Left pointer of the window
        int zeros = 0;     // Count of zeros in current window
        int maxLen = 0;    // Maximum length found

        // Iterate with right pointer
        for (int right = 0; right < nums.size(); right++) {
            // If we encounter a zero, increment zero count
            if (nums[right] == 0) {
                zeros++;
            }

            // If we have more than k zeros, shrink window from left
            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

/*
Example Walkthrough:
nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2

Step-by-step:
- Window expands until we have 2 zeros
- When we hit the 3rd zero, we shrink from left
- We find the maximum window is of size 6: [1,1,1,0,0,0] or [0,0,1,1,1,1]

Alternative Approach (Without while loop):
Instead of shrinking the window, we can maintain a window of size at most maxLen
This ensures we only expand when we find a better solution.
*/
