#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& word) 
    {
       unordered_map<string,int> mp;
       long long count =0;
       for(auto i : word) mp[i]++;

       for(auto it : message){
        if(mp[it]!=0)
        count++;
       } 
       if(count>=2) return true;
       return false;
    }
};