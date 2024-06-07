#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll count =0;
    vector<ll> nextTwo;
    for(int i=0 ; i<n ; i++)
    {
       if(s[i]=='2')
       {
        count++;
        nextTwo.push_back(i);
       }
    }

    if(count>0 && count<3)
    {
       cout << "NO" << endl;
       return;
    }
    cout << "YES" << endl;
    vector<vector<char> > ans(n,vector<char> (n,'='));

    for(int i=0 ;i<n ; i++)
    ans[i][i]= 'X';

    int update = 1;
    for(int i=0 ;i<n ; i++)
    {
        if(s[i]=='2')
        {
            int next = nextTwo[update];
            ans[i][next] = '+';
            ans[next][i] = '-';

            update = (update+1)%nextTwo.size();
        }
    }

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        cout << ans[i][j];
        cout << endl;
    }
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