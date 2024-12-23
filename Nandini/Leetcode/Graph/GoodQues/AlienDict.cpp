#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string findOrder(string dict[], int n, int k) {
        vector<vector<int>> adj(k);
        vector<int> indegree(k, 0);

        for (int i = 0; i < n - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            
            int ind = 0;
            while (ind < s1.size() && ind < s2.size() && s1[ind] == s2[ind]) {
                ind++;
            }
            
            if (ind < s1.size() && ind < s2.size()) {
                adj[s1[ind] - 'a'].push_back(s2[ind] - 'a');
                indegree[s2[ind] - 'a']++;
            }
        }

        queue<int> q;
        for (int i = 0; i < k; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        string out = "";
        for (auto it : ans) {
            out += char(it + 'a');
        }
        return out;
    }
};
