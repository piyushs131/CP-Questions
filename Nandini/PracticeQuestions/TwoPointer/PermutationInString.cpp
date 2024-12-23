#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool is_true(vector<int> &mp1,vector<int> &mp2)
    {
        return mp1==mp2? true:false;
    }
    bool checkInclusion(string s1, string s2) 
    {
       vector<int> mp1(26,0);
       vector<int> mp2(26,0);
       for(auto it : s1)
       {
         mp1[it-'a']++;
       } 
       int n1 = s1.size();
       int n2 = s2.size();
       for(int i=0 ; i<n2 ; i++)
       {
         if(i<n1)
         {
            mp2[s2[i]-'a']++;
         }
         else 
         {
            if(is_true(mp1,mp2)) return true;
            mp2[s2[i-n1]-'a']--;
            mp2[s2[i]-'a']++;
         }
       }
       if(is_true(mp1,mp2)) return true;
       return false;
    }
};