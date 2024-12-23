#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int solve(string& s, int l, int r){
        if (l < 0 || r >= s.size()) return 0;
        if (s[l] != s[r]) return 0;
        return 1 + solve(s, l-1, r+1);
    }

    int countSubstrings(string s) {
        int ans = 0;
        for(int i  = 0; i < s.size(); ++i) ans += 1 + solve(s, i-1, i + 1);
        for(int i = 0;i < s.size()-1; ++i) if (s[i] == s[i+1]) ans += 1 + solve(s, i-1, i+2);
        return ans;
    }
};