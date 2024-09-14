#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) 
    {
       vector<vector<int> > ans;
       int n = arr.size();
       int totalBits = 1<< n;
       for(int bit=0 ;bit<totalBits ; bit++)
       {
        vector<int> v;
        for(int i=0 ; i<n ; i++)
        {
           if(bit & (1<<i)) 
           {
            v.push_back(arr[i]);
           }
        }
        sort(v.begin(),v.end());
        if(find(ans.begin(),ans.end(),v)==ans.end())
        ans.push_back(v);
       } 
       sort(ans.begin(),ans.end());
       return ans;
    }
};