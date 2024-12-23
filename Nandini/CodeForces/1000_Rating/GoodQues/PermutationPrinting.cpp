#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n,-1);
    int c= n;
    for(int i=1 ; i<n; i+=2)
    {
        ans[i] = c;
        c--;
    }
    for(int i=0 ; i<n ;i +=2)
    {
        ans[i] = c;
        c--;
    }
    for(int i=0 ; i<n ; i++)
    cout << ans[i] << " ";

    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}