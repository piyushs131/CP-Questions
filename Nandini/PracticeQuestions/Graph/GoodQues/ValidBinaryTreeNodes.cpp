#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0); 
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                inDegree[leftChild[i]]++;
                if (inDegree[leftChild[i]] > 1) {
                    return false;  
                }
            }
            if (rightChild[i] != -1) {
                inDegree[rightChild[i]]++;
                if (inDegree[rightChild[i]] > 1) {
                    return false;  
                }
            }
        }

        // Find the root (the node with no parent, inDegree == 0)
        int rootCount = 0;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                rootCount++;
            }
        }

        // one root
        if (rootCount != 1) {
            return false;
        }

        vector<bool> visited(n, false);
        queue<int> q;

        // root nodes
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
                visited[i] = true;
                break;
            }
        }

        // bfs
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (leftChild[node] != -1) 
            {
                if (visited[leftChild[node]]) return false;  // Cycle detected
                visited[leftChild[node]] = true;
                q.push(leftChild[node]);
            }

            if (rightChild[node] != -1) {
                if (visited[rightChild[node]]) return false;  // Cycle detected
                visited[rightChild[node]] = true;
                q.push(rightChild[node]);
            }
        }
        // all visited(no disconnected)
        for (bool v : visited) {
            if (!v) return false;
        }

        return true;  
    }
};
