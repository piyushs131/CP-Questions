#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    int a, b, c, d;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            int a = 0, b = 0, c = 0, d = 0;
            if (i - 1 >= 0)
            {
                if(v[i][j] > v[i - 1][j])
                a = v[i - 1][j];
            }
            else 
                a = -1;
            if (j - 1 >= 0 )
            {
                if(v[i][j] > v[i][j - 1])
                b = v[i][j - 1];
            }
            else
                b=-1;
            if (i + 1 < n)
            {
                if(v[i][j] > v[i + 1][j])
                c = v[i + 1][j];
            }
            else 
                c=-1; 
            if (j + 1 < m)
            {
                if(v[i][j] > v[i][j + 1])
                d = v[i][j + 1];
            }
            else 
               d = -1;

            if ((a==-1 || a>0) && (b==-1 || b>0) && (c==-1 || c>0) && (d==-1 || d>0) )
            {
                v[i][j] = max(a,max(b,max(c,d)));
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
