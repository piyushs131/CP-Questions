#include <bits/stdc++.h>
using namespace std;
class Solution {
    static bool cmp(const string &a,const string &b)
    {
         return a.size()<b.size();
    }
public:
    
    int longestStrChain(vector<string>& words) 
    {
       int n = words.size();
       sort(words.begin(),words.end(),cmp);

       unordered_set<string> visited;
       unordered_set<string> s(words.begin(),words.end());
       int ans =0;
       for(int i=n-1 ; i>=0 ; i--)
       {
          if(visited.find(words[i])==visited.end())
          {
            queue<string> q;
            q.push(words[i]);
            int count =0;
            visited.insert(words[i]);
            while(!q.empty())
            {
                int sz = q.size();
                while(sz--)
                {
                   string st = q.front(); q.pop();
                   for(int j=0 ;j <st.size() ; j++)
                   {
                     string temp = st;
                     temp.erase(j,1);
                     if(s.find(temp)!=s.end() && visited.find(temp)==visited.end()){
                        q.push(temp);
                        visited.insert(temp);
                     }
                   }
                }

                count++;
                ans = max(ans,count);
            }
          }
          
       } 
       return ans;
    }
};