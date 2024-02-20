#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<string>> allPalindromicPerms(string S) 
    {
       vector<vector<string> > ans;
       vector<string> v;
       findAll(ans,v,S,0);
       return ans;
    }
    void findAll(vector<vector<string> > &ans,vector<string> &v,string s,int ind)
    {
        if(ind==s.size())
        {
            ans.push_back(v);
            return;
        }
        for(int i=ind; i<s.size() ; i++)
        {
            if(isPal(s,i,ind))
            {
                v.push_back(s.substr(ind,i-ind+1));
                findAll(ans,v,s,i+1);
                v.pop_back();
            }
        }
    }
    
    bool isPal(string s,int end,int st)
    {
        while(st<=end)
        {
            if(s[st]!=s[end])
            return false;
            
            st++;
            end--;
        }
        return true;
    }
};