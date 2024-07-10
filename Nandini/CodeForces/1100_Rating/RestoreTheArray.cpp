#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> t(n-1);
    for(int i=0 ; i<n-1 ; i++)
    cin >> t[i];

    if(n==1)
    {
        cout << 0 << endl;
        return;
    }
    else if(n==2)
    {
        cout << t[0] << " " << t[0] << endl;
        return;
    }

    vector<int> ans;
    int prev=t[0];
    ans.push_back(prev);
    for(int i=0 ; i<n-2 ; i++)
    {
        if(t[i]<=t[i+1] && prev>=t[i])
        {
            ans.push_back(t[i]);
            prev = t[i+1];
        }
        else if(t[i]>t[i+1])
        {
            ans.push_back(t[i+1]);
        }
    }
    ans.push_back(t[n-2]);
    for(int i=0 ;i <n ; i++)
    cout << ans[i] << " ";

    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
