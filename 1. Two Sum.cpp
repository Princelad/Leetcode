#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t size = nums.size();

        unordered_map<int, int> m;

        for (int i = 0; i < size; ++i) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                return { m[complement], i };
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
