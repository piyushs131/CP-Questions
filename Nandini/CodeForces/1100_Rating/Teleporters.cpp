#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n,c;
    cin >> n >> c;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i]+i+1;
    }

    sort(arr.begin(),arr.end());
    ll sum =0;
    for(ll i=0 ; i<n ; i++)
    {
        sum+=arr[i];
        if(sum>c)
        {
            cout << i << endl;
            return;
        }
    }
    cout << n  << endl;
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
