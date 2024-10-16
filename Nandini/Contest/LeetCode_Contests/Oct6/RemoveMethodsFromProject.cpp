#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invo) 
    {
       map<int,int> sus;
       vector<int> adj[n];
       for(auto it : invo)
       {
         adj[it[0]].push_back(it[1]);
       } 
       queue<int>q;
       q.push(k);
       sus[k] = 1;
       while(!q.empty())
       {
         int tp = q.front(); q.pop();
         for(auto nbr : adj[tp])
         {
            if(sus.find(nbr) == sus.end())
            {
                sus[nbr] = 1;
                q.push(nbr);
            }
         }
       }

    //    for(auto it : sus)
    //    {
    //     cout << it.first << ", " ;
    //    }
       
       vector<int> ans;
       bool flag = false;
        for(int i = 0; i < n; i++)
        {
            if(sus.find(i) != sus.end())
                continue;

            for(auto nbr : adj[i])
            {
                if(sus.find(nbr) != sus.end())
                {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            ans.push_back(i);
        }

        if(flag) {
            ans.clear();
            for(int i=0 ; i<n ; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }
       return ans;
    }
};
