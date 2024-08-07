#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) 
    {
       int a =-1,b=-1,c=-1;
       int n = s.size();
       int i =0,ans = 0;
       while(i<n)
       {
         if(s[i]=='a') a = i;
         else if(s[i]=='b') b = i;
         else c= i;

         if(a!=-1 && b!=-1 && c!=-1) 
         ans += min(a,min(b,c))+1;

         i++;
       } 
       return ans;
    }
};