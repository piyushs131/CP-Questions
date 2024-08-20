#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) 
    {
        reverse(s.begin(),s.end());
        int n = s.size();
        int i=0,l=0,r=0;
        while(i<n)
        {
            while(i<n && s[i]==' ')i++;
            while(i<n && s[i]!=' ') s[r++] = s[i++];

            if(l<r)
            {
                reverse(s.begin()+l,s.begin()+r);
                s[r++] = ' ';
                l = r;
            }
            i++;
        }
        if(r>0) s.resize(r-1);
        return s;
    }
};