#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts, ends;

        for (auto& f : flowers) {
            starts.push_back(f[0]);
            ends.push_back(f[1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> result;
        for (int person : people) {
            // Count flowers that have started by person's time
            int bloomed = upper_bound(starts.begin(), starts.end(), person) - starts.begin();
            // Count flowers that have ended before person's time
            int wilted = lower_bound(ends.begin(), ends.end(), person) - ends.begin();
            result.push_back(bloomed - wilted);
        }
        return result;
    }
};