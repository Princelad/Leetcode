#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 2) return n;

        int write = 2;
        for (int read = 2; read < n; ++read) {
            if (nums[read] != nums[write - 2]) {
                nums[write] = nums[read];
                ++write;
            }
        }

        return write;
    }
};