#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, x, y, d;
        cin >> n >> m >> x >> y >> d;
        x--, y--;

        ll x1 = x - d, x2 = x + d;          
        ll y1 = y - d, y2 = y + d;

        if ((x1 <= 0 && x2 >= n - 1) || (y1 <= 0 && y2 >= m - 1) || (x1 <= 0 && y1 <= 0) || (x2 >= n - 1 && y2 >= m - 1))
            cout << -1 << endl;
        else
            cout << n + m - 2 << endl;
    }
}
