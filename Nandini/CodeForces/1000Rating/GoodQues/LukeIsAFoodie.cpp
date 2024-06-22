#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n,x;
    cin >> n >> x;
    ll total =0,l=-1,r = 1e9+5;
    for(int i=0 ; i<n ; i++)
    {
        ll a;
        cin >> a;
        if(a+x<l || a-x>r)
        {
            total++;
            l = a-x,r = a+x;
        }
        else 
        {
            l = max(l,a-x);
            r = min(r,a+x);
        }
    }
    cout << total << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}
