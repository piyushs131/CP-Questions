#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin >> n;
    ll a=1;

    for (ll i = 2; i* i <= n; ++i)
    {
        if(n%i==0)
        {
            a = n/i;
            break;
        }
    }

    cout << a << " " << n-a;
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
    return 0;
}
