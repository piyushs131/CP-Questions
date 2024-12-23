#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int q,k;
    cin >> q;
    vector<int>arr;
    for(int i=0 ; i<q ; i++)
    {
        cin >> k;
        arr.push_back(k);
    }
    vector<int> ans;
    ans.push_back(1);
    bool flag = true,first = true;
    ll curr = arr[0];
    for(int i=1 ;i <q ; i++)
    {
        if(curr<=arr[i] && flag==true)
        {
            ans.push_back(1);
            curr = arr[i];
        }
        else if(arr[i]<=arr[0] && (curr<=arr[i] || flag==true))
        {
          ans.push_back(1);
          curr = arr[i];
          first = false;
          flag = false;
        }
        else 
        ans.push_back(0);
    }
    for(auto it : ans)
    cout << it;

    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    solve();
}
