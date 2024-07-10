#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    if(n==1)
    {
        cout << "YES" << endl;
        return;
    }
    
    int count = k;
    bool f = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != grid[n - i - 1][n - j - 1]) 
            { 
               if(count==0)
               {
                 f = false;
                 break;
               }  
               count--;
               grid[i][j] = grid[n - i - 1][n - j - 1];
            }
        }
        if(f==false)  break;
    }

    int ct =0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ;j ++)
        {
            if(grid[i][j]!=grid[n-i-1][n-j-1])
            ct++;
        }
    }
    if(ct!=0) cout << "NO" << endl;
    else {
        if(count%2==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
