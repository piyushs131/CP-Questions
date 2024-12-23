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

    if(n==1 || n==2)
    {
        for(int i=0 ; i<n ; i++)
        cout << v[i] << " ";
        return;
    }
    else if(v[0] == n)
    {
        cout << v[0] << " ";
        for(int i=n-1 ; i>0 ; i--)
        cout << v[i] << " ";
        return;
    }
    else if(v[n-1] == n)
    {
        for(int i=n-2 ; i>=0; i--)
        cout << v[i] <<" ";
        cout << v[n-1] ;
        return;
    }
    cout << -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
}