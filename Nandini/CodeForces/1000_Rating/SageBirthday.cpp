#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int> ans(n);
    int j=0;
    int i;
    for( i=1 ; i<n ; i+=2)
    {
        ans[i] = arr[j];
        j++;
    }
    if(i==n)
    cout << j << endl;
    else 
    cout << j-1 << endl;
    for( i=0 ; i<n ; i+=2)
    {
        ans[i] = arr[j++];
    }
    for( i=0 ; i<n ; i++)
    cout << ans[i] << " ";
}
int main()
{
    solve();
}