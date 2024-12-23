#include <vector>
#include <map>
using namespace std;

class neighborSum {
    int n;
    vector<vector<int>> v;
    map<int,int> nbr;
    map<int,int> dia;

public:
    neighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        v = grid; 
    }
    
    int adjacentSum(int value) {
        if(nbr.find(value) != nbr.end()) return nbr[value];

        int i, j; 
        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j) {
                if(v[i][j] == value)
                    goto found;
            }
        }
        found:

        int ans = 0;
        if(i > 0) ans += v[i-1][j]; 
        if(j > 0) ans += v[i][j-1];
        if(i < n-1) ans += v[i+1][j];
        if(j < n-1) ans += v[i][j+1];
        nbr[value] = ans;

        int diag = 0;
        if(i > 0 && j > 0) diag += v[i-1][j-1]; 
        if(j > 0 && i < n-1) diag += v[i+1][j-1];
        if(i < n-1 && j < n-1) diag += v[i+1][j+1];
        if(j < n-1 && i > 0) diag += v[i-1][j+1];
        dia[value] = diag;

        return ans;
    }
    
    int diagonalSum(int value) {
        if(dia.find(value) != dia.end()) return dia[value];
        
        int i, j; 
        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j) {
                if(v[i][j] == value)
                    goto found;
            }
        }
        found:

        int diag = 0;
        if(i > 0 && j > 0) diag += v[i-1][j-1]; 
        if(j > 0 && i < n-1) diag += v[i+1][j-1];
        if(i < n-1 && j < n-1) diag += v[i+1][j+1];
        if(j < n-1 && i > 0) diag += v[i-1][j+1];
        dia[value] = diag;

        return diag;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
