#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n, k, s, mini = INT_MAX;
    cin >> n;
    vector<vector<ll>> v;

    for (int i = 0; i < n; i++)
    {
        vector<ll> arr;
        cin >> s;
        while (s--)
        {
            cin >> k;
            mini = min(mini, k);
            arr.push_back(k);
        }
        sort(arr.begin(), arr.end());
        v.push_back(arr);
    }
    ll sum = 0;
    sum += mini;
    vector<ll> arr;
    for (int i = 0; i < n; i++)
    {
        if (v[i].size() > 1)
        {
            arr.push_back(v[i][1]);
            sum += v[i][1];
        }
        else 
        {
           arr.push_back(v[i][0]);
            sum += v[i][0];   
        }
    }
    sort(arr.begin(), arr.end());
    sum -= arr[0];
    cout << sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}