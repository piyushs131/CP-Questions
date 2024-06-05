#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    string s1,s2;
    cin >> s1 >> s2;
    int n= s1.size();
    bool flag = 0;
    for(int i=0 ; i<n ; i++)
    {
        if(s1[i]=='0' && s2[i]=='0' && s1[i+1]=='1' && s2[i+1]=='1')
        {
            flag = 1;
            break;
        }
    }
    if(flag) cout << "YES" ;
    else cout << "NO";
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