#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,maxi = 0;
    cin >> n;
    vector<int> v1(n),v2(n);
    for(int i=0 ; i<n ; i ++)
    cin >> v1[i];

    for(int i=0 ; i<n ; i ++)
    cin >> v2[i];

    int prev =v1[0],ans = INT_MIN;
    for(int i=0 ;i<n ; i++)
    {
        if(v1[i]==v2[i] && prev ==v1[i])
        {
            prev = v1[i];
            maxi += 2;
        }
        else if(v1[i]==v2[i] && prev!=v1[i] )
        {
            maxi = 2;
            prev = v1[i];
        }
        else if(v1[i]!=v2[i])
        {
            if(prev == v1[i])
            {
                maxi+=1;
                ans = max(ans,maxi);
                prev = v2[i];
                maxi = 1;
            }
            else if(prev == v2[i])
            {
                maxi += 1;
                ans = max(ans,maxi);
                prev = v1[i];
                maxi = 1;
            }
            else 
            {
                ans = max(ans,maxi);
                maxi = 1;
                prev = v1[i];
            }
        }
        ans = max(ans,maxi);
    }
    for(int i=0 ;i<n ; i++)
    {
        if(v1[i]==v2[i] && prev ==v1[i])
        {
            prev = v1[i];
            maxi += 2;
        }
        else if(v1[i]==v2[i] && prev!=v1[i] )
        {
            maxi = 2;
            prev = v1[i];
        }
        else if(v1[i]!=v2[i])
        {
            if(prev == v1[i])
            {
                maxi+=1;
                ans = max(ans,maxi);
                prev = v2[i];
                maxi = 1;
            }
            else if(prev == v2[i])
            {
                maxi += 1;
                ans = max(ans,maxi);
                prev = v1[i];
                maxi = 1;
            }
            else 
            {
                ans = max(ans,maxi);
                maxi = 1;
                prev = v2[i];
            }
        }
        ans = max(ans,maxi);
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
/*
1
5
1 2 2 2 2
2 1 1 1 1
*/