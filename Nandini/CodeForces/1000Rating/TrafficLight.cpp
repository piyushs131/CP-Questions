#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    char ch;
    cin >> n >> ch;
    string s;
    cin >> s;
    if (ch == 'g')
    {
        cout << 0;
        return;
    }
    vector<int> v;
    for(int i=0 ; i<n ;i++)
    {
        if(s[i]=='g')
        {
            v.push_back(i);
        }
    }
    int ans =INT_MIN,ind,steps =0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ch)
        {
            steps =INT_MAX;
            for(int j=0 ;j<v.size() ;j++)
            {
                if(v[j]>i)
                steps = min(steps,v[j]-i);
                else 
                {
                   steps = min(steps,n-1-i + v[j]+1);
                }
            }
        }
        ans = max(ans,steps);
    }
    cout << ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}