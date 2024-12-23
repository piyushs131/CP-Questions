#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int a[n];
    unordered_map<int, int> mp;
    unordered_map<int, int> cp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    int b[n];

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        cp[b[i]] = 1;
    }

    int count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        int x = mp[a[i]];
        mp[a[i]] = max(x, count);
    }

    count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] == b[i + 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        int x = cp[b[i]];
        cp[b[i]] = max(x, count);
    }
    int ans = 0;
    for (auto c : mp)
    {
        ans = max(ans, c.second + cp[c.first]);
    }
    for (auto c : cp)
    {
        ans = max(ans, c.second + mp[c.first]);
    }
    cout << ans << endl;
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