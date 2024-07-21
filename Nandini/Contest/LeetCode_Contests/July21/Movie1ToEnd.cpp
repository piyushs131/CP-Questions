#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveLast(string &s, int ind) {
        string t = "";
        if(ind > 0)
            t = s.substr(0, ind);
        int i;
        for (i = ind + 1; i < s.size(); i++) {
            if (s[i] == '1')
                break;
            t += s[i];
        }
        t += '1';
        if (i != s.size()) {
            t += s.substr(i, s.size() - i);
        }
        s = t;
    }

    int maxOperations(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1' && s[i + 1] == '0') {
                count++;
                moveLast(s, i);
                i = -1;
            }
        }
        return count;
    }
};