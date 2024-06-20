#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool recurse(ll n, ll m, map<ll, bool> &vis)
{
    if (n == m)
        return true;

    else
    {
        if (n > m && n % 3 == 0)
        {
            if (!vis.count(n / 3))
            {
                vis[n / 3] = recurse(n / 3, m, vis);
            }
            if (!vis.count(2 * (n / 3)))
                vis[2 * (n / 3)] = recurse(2 * (n / 3), m, vis);

            return vis[n / 3] || vis[2 * (n / 3)];
        }
        return false;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    map<ll, bool> vis;
    bool res = recurse(n, m, vis);
    if (res)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}