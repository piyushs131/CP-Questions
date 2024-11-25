#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) 
    {
       map<string,int> mp1;
       map<string,int> mp2;
       int subSize = s.size()/k, st=0,n = s.size();
       int e = subSize-1;
       while(e<n)
       {
         string str1 = s.substr(st,subSize);
         string str2 = t.substr(st,subSize);
         mp1[str1]++;
         mp2[str2]++;
         
         st= e+1;
         e = e+subSize;
       }
       if(mp1==mp2)
       return true;

       return false;
    }
};