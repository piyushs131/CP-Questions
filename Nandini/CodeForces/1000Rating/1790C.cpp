#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, ind1 = -1, last = -1, ind2 = -1;
        vector<int> v;
        cin >> n;
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> diff;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            diff[k]++;
            if (diff[k] == 1 && (last == -1 || diff[last] != 1))
            {
                ind1 = i;
                last = k;
            }
            else if (diff[k] == 1)
                ind2 = i;

            v.push_back(k);
            for (int i = 1; i < n - 1; i++)
            {
                cin >> k;
                v.push_back(k);
            }
            mp[i] = v;
            v.clear();
        }

        if (ind2 == -1)
        {
            vector<int> v1 = mp[ind1];
            if (diff[v1[0]] == 1)
            {
                if(ind1-1>=0)
                cout << mp[ind1-1][0] << " ";
                else if(ind1+1<n)
                cout << mp[ind1+1][0] << " ";
                for (int i = 0; i < n - 1; i++)
                    cout << v1[i] << " ";
            }
            cout << endl;
            continue;
        }
        vector<int> v1 = mp[ind1];
        vector<int> v2 = mp[ind2];
        if (diff[v1[0]] == 1)
        {
            cout << v2[0] << " ";
            for (int i = 0; i < n - 1; i++)
                cout << v1[i] << " ";
        }
        else
        {
            cout << v1[0] << " ";
            for (int i = 0; i < n - 1; i++)
                cout << v2[i] << " ";
        }
        cout << endl;
    }
}
