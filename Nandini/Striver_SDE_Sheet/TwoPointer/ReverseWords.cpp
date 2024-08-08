#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) 
    {
       int j=0;
       string str = " ",ans="";
       int n = s.size();
       while(j<n)
       {
         while(j<n && s[j]!=' ')
         {
            str+=s[j];
            j++;
         }
            reverse(str.begin(),str.end());
            ans+= str;
            str= " ";
            j++;
       }  
       ans.pop_back();
       return ans;
    }
};