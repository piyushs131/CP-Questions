#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<ll,ll> freq;
    vector<ll>ans;
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for(auto it : freq)
    {
       if(it.second>1) ans.push_back(it.first);
    }

    if(ans.size()<2) {
        cout << "-1" ;
        return;
    }

    for(auto it : arr)
    {
        if(it==ans[0])
        {
            ans[0] =-1;
            cout << "2" << " ";
        }
        else if(it==ans[1])
        {
            ans[1] = -1;
            cout << "3" << " ";
        }
        else 
        {
            cout << "1" << " ";
        }
    }
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