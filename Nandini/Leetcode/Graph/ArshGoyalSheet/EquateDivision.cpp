#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, string src, string dst, unordered_set<string>& visited) {
        if (src == dst) return 1.0;
        visited.insert(src);

        for (auto& neighbor : graph[src]) {
            if (visited.find(neighbor.first) == visited.end()) {
                double result = dfs(graph, neighbor.first, dst, visited);
                if (result != -1.0) return result * neighbor.second;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            graph[u][v] = val;
            graph[v][u] = 1.0 / val;
        }

        vector<double> result;
        for (auto& query : queries) {
            string src = query[0];
            string dst = query[1];
            if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) {
                result.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                result.push_back(dfs(graph, src, dst, visited));
            }
        }
        return result;
    }
};
