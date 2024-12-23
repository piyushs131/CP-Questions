#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n;
        vector<int> v;
        for(int i=0 ; i<n ; i++)
        {
            cin >> k;
            v.push_back(k);
        }
        int i=0;
        while(i+1<n && v[i]<=v[i+1])i++;
        while(i+1<n && v[i]>=v[i+1])i++;
        if(i+1==n)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
