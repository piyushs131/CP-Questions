#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) 
    {
       unordered_map<int,int> mp;
       int n= nums.size();
       vector<int> v;
       for(int i=0 ;i <n ; i++) mp[nums[i]]++;
       for(auto it : mp)
       {
         if(it.second>1)v.push_back(it.first); 
       } 
       return v;
    }
};