#include <bits/stdc++.h>
using namespace std;

void solve()
{
        int n, c, d,k,mini=INT_MAX;
        cin >> n >> c >> d;
        map<int,int> mp;
        for (int i = 0; i < n * n; i++)
        {
            cin >> k;
            mini = min(mini,k);
            mp[k]++;
        }

        int first = mini,row_move;
        for(int i=0 ;i<n ;i++)
        {
            first = mini+i*c;
            row_move= first;
            if(!mp[row_move])
            {
                cout << "NO" << endl;
                return;
            }
            for(int j=0 ; j<n ; j++)
            {
                row_move = first+j*d;
                if(!mp[row_move])
                {
                    cout << "NO" << endl;
                    return;
                }
                mp[row_move]--;
            }
        }
        cout << "yes" << endl;
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
