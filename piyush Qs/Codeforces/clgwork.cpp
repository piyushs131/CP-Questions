#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(4, vector<int>(n));
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    vector<int> res;

    // int j = 1;
    // int ans = res.push_back(matrix[i][j])

    int ans = min(4,n);
    
    for (int i = 0; i < ans; ++i) {
        res.push_back(matrix[i][i]);
    }

   
    for (int i = 0; i < ans; ++i) {
        res.push_back(matrix[3 - i][i]);
    }
    
    for (int x : res) {
        cout << x << " ";
    }
    
    return 0;
}
