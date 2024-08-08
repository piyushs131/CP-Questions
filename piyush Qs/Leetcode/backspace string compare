class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a="",b="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='#' && a.empty()) continue;
            else if(s[i]=='#' && !a.empty()) a.pop_back();
            else a+=s[i];
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#' && b.empty()) continue;
            else if(t[i]=='#' && !b.empty()) b.pop_back();
            else b+=t[i];
        }
        return a==b;
    }
};