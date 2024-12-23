#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k, sum = 0, b;
    cin >> n >> k;
    vector<ll> v, pre(n + 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> b;
        v.push_back(b);
    }
    ll maxi = 0;
    sort(v.begin(), v.end());
    for (ll i = 0; i < n; i++)
    {
        sum += v[i];
        pre[i + 1] = pre[i] + v[i];
    }
    for (ll i = 0; i <= k; i++)
    {
        maxi = max(maxi, pre[n - i] - pre[2 * (k - i)]);
    }
    cout << maxi << endl;
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
