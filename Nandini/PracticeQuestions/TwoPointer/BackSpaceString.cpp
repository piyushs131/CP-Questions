#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string processString(const string &s) {
        string result;
        for (char c : s) {
            if (c == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
    
    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);
    }
};
