#include <vector>
using namespace std;
class Solution {
public:
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n, 0); // Initialize all colors as 0
        return canColor(graph, m, n, 0, color);
    }

    bool canColor(bool graph[101][101], int m, int n, int ind, vector<int>& color) {
        if (ind == n)
            return true;

        for (int c = 1; c <= m; c++) 
        {
            if (isPossible(graph, n, ind, c, color)) 
            {
                color[ind] = c;
                if (canColor(graph, m, n, ind + 1, color))
                    return true;
                color[ind] = 0; 
            }
        }
        return false;
    }

    bool isPossible(bool graph[101][101], int n, int ind, int c, vector<int>& color) 
    {
        for (int i = 0; i < n; i++) {
            if (graph[ind][i] && color[i] == c)
                return false;
        }
        return true;
    }
};
