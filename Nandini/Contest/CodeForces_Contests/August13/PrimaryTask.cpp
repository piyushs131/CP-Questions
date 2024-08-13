#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    string n;
    cin >> n;
    if(n.size()==1 || n.size()==2)
    {
        cout << "NO" << endl;
        return;
    }
    if(n[0]=='1' && n[1]=='0' && n[2]!='0' && (n[2]!='1' || n.size()>3))
    cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
