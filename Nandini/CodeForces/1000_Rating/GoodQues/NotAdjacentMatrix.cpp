#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    int i;
    if(n==1)
    {
        cout << 1 << endl;
        return;
    }
    if(n==2)
    {
        cout << -1 << endl;
        return;
    }
    vector<vector<int> > ans(n,vector<int> (n));
    int c = 1;
    for(int i=0 ; i<n ; i++)
    {
        ans[i][i] = c;
        c++;
    }
    for(int i=1 ; i<n ; i++)
    {
        for(int j=0 ; j<i ; j++)
        {
            ans[j][i] = c;
            ans[i][j] = c+1;
            c+=2;
        }
    }

    for(int i=0 ;  i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cout << ans[i][j] << " ";
        }
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