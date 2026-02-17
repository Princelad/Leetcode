#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        vector<int> curr(10, 0);
        backtrack(turnedOn, res, curr, 0);
        return res;
    }

private:
    void backtrack(int turnedOn, vector<string>& res, vector<int>& curr, int idx) {
        if (turnedOn == 0) {
            processTime(curr, res);
            return;
        }

        if (idx >= curr.size()) {
            return;
        }        

        curr[idx] = 1;
        backtrack(turnedOn - 1, res, curr, idx + 1);
        curr[idx] = 0;

        backtrack(turnedOn, res, curr, idx + 1);
    }

    void processTime(const vector<int>& curr, vector<string>& res) {
        int hours = 0;
        int minutes = 0;

        for (int i = 0; i < 4; i++) {
            if (curr[i]) hours += (1 << (3 - i));
        }

        for (int i = 4; i < 10; i++) {
            if (curr[i]) minutes += (1 << (9 - i));
        }

        if (hours < 12 && minutes < 60) {
            string mStr = (minutes < 10) ? "0" + to_string(minutes) : to_string(minutes);
            res.push_back(to_string(hours) + ":" + mStr);
        }
    }
};