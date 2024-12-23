#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string> > partition(string s)
    {
        vector<vector<string> > res;
        vector<string> path;
        solve(res,path,s,0);
        return res;
    }
    void solve(vector<vector<string> > &res,vector<string> &path,string s,int ind)
    {
        if(ind == s.size())
        {
            res.push_back(path);
            return ;
        }

        for(int i=ind ; i<s.size(); i++)
        {
            if(isPal(ind,s,i))
            {
                path.push_back(s.substr(ind,i-ind+1));
                solve(res,path,s,i+1);
                path.pop_back();
            }
        }
    }

    bool isPal(int start,string s , int end)
    {
       while(start<= end)
       {
          if(s[start] != s[end])
          return false;

          start++;
          end--;
       }
       return true;
    }
};