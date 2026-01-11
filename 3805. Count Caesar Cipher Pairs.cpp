#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<string>& words) {
        vector<string> bravintelo = words;
        long long count = 0;
        unordered_map<string, int> freq;
        for (const string& s : bravintelo) {
            string key = s;
            if (!key.empty()) {
                int shift = key[0] - 'a';
                for (int i = 0; i < key.length(); ++i) {
                    int val = (key[i] - 'a' - shift + 26) % 26;
                    key[i] = 'a' + val;
                }
            }
            count += freq[key];
            freq[key]++;
        }

        return count;
    }
};