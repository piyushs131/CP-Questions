#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>>& adj, unordered_map<string, int>& vis, string curr, unordered_map<string, double>& val, double assign) {
        vis[curr] = 1;
        val[curr] = assign;

        for (auto it : adj[curr]) {
            if (!vis[it.first]) {
                dfs(adj, vis, it.first, val, assign * it.second);
            }
        }
    }

    bool isConnected(string a, string b, unordered_map<string, vector<pair<string, double>>>& adj, unordered_map<string, int>& vis) {
    if (a == b) return true;
    vis[a] = 1;
    
    for (auto it : adj[a]) {
        if (!vis[it.first]) {
            if (isConnected(it.first, b, adj, vis)) {
                return true;
            }
        }
    }
    return false;
}

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& value, vector<vector<string>>& queries) {
        unordered_set<string> st;
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < eq.size(); i++) 
        {
            adj[eq[i][0]].push_back({eq[i][1], 1.0 /value[i]});
            adj[eq[i][1]].push_back({eq[i][0],  value[i]});
            st.insert(eq[i][0]);
            st.insert(eq[i][1]);
        }

        unordered_map<string, double> val;
        unordered_map<string, int> vis;

        for (const auto& s : st) 
        {
            if (!vis[s]) 
            {
                dfs(adj, vis, s, val, 1.0);
            }
        }
        // for(auto it : val)
        // {
        //     cout << it.first <<" " << it.second << endl;
        // }
        vector<double> result;
        for (auto& q : queries) 
        {
            unordered_map<string, int> vis;
            if (val.find(q[0]) != val.end() && val.find(q[1]) != val.end() && vis[q[0]] == vis[q[1]] && isConnected(q[0],q[1],adj,vis)) 
            {
                result.push_back(val[q[0]] / val[q[1]]);
            } 
            else {
                result.push_back(-1.0); 
            }
        }

        return result;
    }
};
