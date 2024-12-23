#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n ;
    cin >> n;
    ll ans =0;
    while(n)
    {
        ans+=n%10;
        n = n/10;
    }
    cout << ans << endl;
}
int main() 
{
    int t;
    cin >> t;
    while(t--)
    solve();
}
