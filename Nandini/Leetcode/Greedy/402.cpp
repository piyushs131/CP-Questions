#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) 
    {
       int n = num.size();
        if(n<=k) return "0";
        
        string res ="";
        for(int i=0 ; i<n ; i++)
        {
            while(!res.empty() && k>0 && res.back()> num[i])
            {
                res.pop_back();
                k--;
            }
            if (res.empty() && num[i] == '0') continue;
            res+= num[i];
        }
        while(k>0 && res.size())
        {
            res.pop_back();
            k--;
        }
        return res.size()?res:"0";
    }
};
