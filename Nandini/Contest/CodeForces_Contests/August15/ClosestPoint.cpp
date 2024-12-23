#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    if(n==2)
    {
       if(abs(v[0]-v[1])<2)
       {
        cout << "NO" << endl;
       }
       else cout << "YES" << endl;
    }
    else 
    {
        cout << "NO" << endl;
        return;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
