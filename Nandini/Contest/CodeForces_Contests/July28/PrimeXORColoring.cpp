#include <bits/stdc++.h>
using namespace std;
#define lli long long int

vector<vector<int> > smallRes = {
    {1,1},
    {2,1,2},
    {2,1,2,2},
    {3,1,2,2,3},
    {3,1,2,2,3,3},
    {4,1,2,2,3,3,4},
};
 
void solve() {
    // odd-odd -> XOR-2 prime so edge
    // even-even-> XOR-2 prime so edge
    lli n;
    cin>>n;
    if(n<=6)
    {
        const auto cur=smallRes[n-1];
        cout<<cur[0]<<endl;
        for(lli j=1;j<=n;j++)
            cout<<cur[j]<<" \n"[j==n];
        return;
    }
 
    cout<<4<<endl;
    for(lli j=0;j<n;j++)
    {
        const lli r=j%4;
        cout<<r+1<<" \n"[j+1==n];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
