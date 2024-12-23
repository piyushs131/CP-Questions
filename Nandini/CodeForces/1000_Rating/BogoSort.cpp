#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++)
    cin >> arr[i];

    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    for(int i=0 ; i<n ; i++)
    cout << arr[i] << " ";

    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
}