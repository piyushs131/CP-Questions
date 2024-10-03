#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void removeHash(string &s)
    {
        stack<char> st;
        for(auto it : s)
        {
            if(it=='#' && !st.empty()) st.pop();
            else if(it=='#' && st.empty()) continue;
            else st.push(it);
        }
        s="";
        while(!st.empty()) s+= st.top(), st.pop();
        reverse(s.begin(),s.end());
    }
    bool backspaceCompare(string s, string t) 
    {
       removeHash(s);
       removeHash(t);
       return s==t?true:false; 
    }
};