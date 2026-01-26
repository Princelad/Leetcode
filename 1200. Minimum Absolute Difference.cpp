#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int min_diff = numeric_limits<int>::max();
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
                ans.clear();
                ans.push_back({ arr[i - 1], arr[i] });
            }
            else if (diff == min_diff) {
                ans.push_back({ arr[i - 1], arr[i] });
            }
        }

        return ans;
    }
};