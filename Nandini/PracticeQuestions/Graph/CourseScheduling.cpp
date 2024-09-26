#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) 
    {
        vector<int> adj[numCourses]; 
        vector<int> indegree(numCourses, 0);  
        int n = pre.size();

        for(int i = 0; i < n; i++)
        {
            indegree[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++)  
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        if(q.empty()) return false; 

        while(!q.empty())
        {
            int tp = q.front(); q.pop();
            cout << "tp=" << tp << endl;
            for(int it = 0; it < adj[tp].size(); it++)
            {
                indegree[adj[tp][it]]--;
                if(indegree[adj[tp][it]] == 0)
                {
                    q.push(adj[tp][it]);
                }
            }
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] != 0) return false;
        } 
        return true;
    }
};
