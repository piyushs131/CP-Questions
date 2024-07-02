#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPal(vector<int> &arr)
{
    int n = arr.size();
    for(int i=0 ; i<n/2 ; i++)
    if(arr[i]!=arr[n-i-1]) return false;

    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0 ;i <n ; i++)
    cin >> arr[i];

    if(isPal(arr))
    {
        cout << 0 << endl;
        return;
    }
    vector<int> diff;
    for(int i=0 ; i<n/2 ; i++)
    {
      diff.push_back(abs(arr[i]-arr[n-i-1]));
    }
    int r=diff[0];
    for(int i=1; i<diff.size() ; i++)
    {
        r = __gcd(diff[i],r);
    }
    cout << r << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
