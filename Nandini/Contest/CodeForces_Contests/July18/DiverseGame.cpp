#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    if (n == 1 && m == 1)
    {
        cout << -1 << endl;
        return;
    }
    vector<vector<int>> b(n, vector<int>(m, 0));
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           if(i==0 && j==0) continue;
           
           if(j==0)
           {
              b[i][j] = a[i-1][m-1];
           }
           else
           b[i][j] = a[i][j-1];
        }
       
    }

    b[0][0] = a[n-1][m-1];

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        cout << b[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
