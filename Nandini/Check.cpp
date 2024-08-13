#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0 ; i<n ; i++) cin >> v[i];
    string s;
    cin >> s;

    int left =0 ,right = n-1;
    while(left <n && v[left]!='L') left++;
    while(right>=0 && v[right]!='R') right--;
}
int main()
{
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
