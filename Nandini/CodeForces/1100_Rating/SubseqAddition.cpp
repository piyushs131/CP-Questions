#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++)
    cin >> v[i];

    sort(v.begin(),v.end());
    if(v[0]!=1) 
    {
        cout << "NO" << endl;
        return;
    }
    ll sm = 1;
    for(int i=1 ; i<n ; i++)
    {
        if(v[i]<=sm)
        {
            sm+=v[i];
        }
        else 
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
