#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    if(n==1)
    {
        cout << 1;
        return;
    }
    else if(n==2)
    {
        cout << 2 << " " << 1 ;
        return;
    }
    vector<ll> v;
    for(ll i=1 ; i<=n ; i++)
    {
        v.push_back(i);
    }
    swap(v[2],v[n-1]);
    swap(v[0],v[1]);
    swap(v[1],v[n/2]);
    for(int i=0 ;i<n ; i++)
    cout << v[i] << " ";
    
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
        cout << endl;
    }
}