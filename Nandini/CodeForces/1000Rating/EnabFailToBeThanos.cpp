#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(2*n);
    for(int i=0 ;i <2*n ; i++)
    cin >> arr[i];

    sort(arr.begin(),arr.end());
    int s1=0,s2=0;
    for(int i=0 ; i<2*n ; i++)
    {
        if(i<n)
        s1+= arr[i];
        else 
        s2+=arr[i];
    }
    if(s1==s2)
    {
        cout << -1 << endl;
    }
    else 
    {
        for(int i=0 ; i<2*n ; i++)
        cout << arr[i] << " ";
        cout << endl;
    }
}
int main()
{
        solve();
}