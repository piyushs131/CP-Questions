#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
       int s1 = s.size(),s2=t.size();
       int i=0,j=0; 
       while(j<s2)
       {
          if(i==s1) return true;

          if(s[i]==t[j])
          i++;
          
          j++;
       }
       if(i==s1) return true;
       return false;
    }
};