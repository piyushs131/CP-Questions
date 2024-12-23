#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, x;
    cin >> n >> x;
    int sum = 0;
    
    for (int i = 1; i <= n; i++)
    {
        if (x % i == 0)
        {
            ll quotient = x / i;
            if (quotient >= 1 && quotient <= n)
            {
                sum++;
            }
        }
    }
    cout << sum;
}

int main()
{
    solve();
    return 0;
}
