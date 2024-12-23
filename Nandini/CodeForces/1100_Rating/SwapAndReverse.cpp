#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k%2==0)
    {
        sort(s.begin(),s.end());
        cout << s << endl;
    }
    else 
    {
        vector<char> odd,even;
        for(int i=0 ; i<n ; i++)
        {
            if(i%2==0) odd.push_back(s[i]);
            else even.push_back(s[i]);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        int a=0,b=0;
        for(int i=0 ; i<n ; i++)
        {
            if(i%2==0) cout << odd[a++];
            else cout << even[b++];
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
