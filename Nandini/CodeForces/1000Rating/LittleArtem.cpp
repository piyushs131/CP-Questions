#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i=0 ;i <n-1 ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            cout <<'B';
        }
        cout << endl;
    }
    for(int i=0 ; i<m-1 ; i++)
    {
        cout << "B";
    }
    cout << "W" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}