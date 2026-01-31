#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char letter : letters) {
            if ((int)(letter - target) > 0) {
                return letter;
            }
        }
        return letters[0];
    }
};