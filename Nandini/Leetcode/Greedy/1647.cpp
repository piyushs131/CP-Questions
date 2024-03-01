#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(pair<char,int> a,pair<char,int> b)
    {
        return a.second < b.second;
    }
    int minDeletions(string s) 
    {
        unordered_map<char,int> mp;
        vector<pair<char,int> >v;
        int i,n = s.size();
        for(i=0 ;i <n ; i++)
        {
            mp[s[i]]++;
        }
        for(auto it : mp)
        {
            v.push_back(it);
        }
        sort(v.begin(),v.end(),cmp);
        
        n = v.size();
        int count =0;
        for(i=0 ; i<n-1 ; i++)
        {
            if(v[i].second==v[i+1].second && v[i].second!=0)
            {
                count++;
                v[i].second--;
                if(i>0)
                i = i-2;
            }
        }
        return count;
    }
};