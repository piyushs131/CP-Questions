#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int remPlaces, remElements, next;
    while (t--)
    {
        int n, k;
        cin >> k >> n;
        vector<int> ans;
        ans.push_back(1);
        int remaining = k;
        int diff = 1;
        for (int i = 2; i <= k; i++)
        {
            next = ans.back() + diff;
            remPlaces = k - i;
            remElements = n - next;
            if (remPlaces <= remElements)
            {
                ans.push_back(next);
                diff++;
            }
            else
                ans.push_back(ans.back() + 1);
        }
        for (int num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
