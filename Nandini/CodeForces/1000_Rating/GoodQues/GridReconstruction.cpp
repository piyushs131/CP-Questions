#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int max = 2 * n;
        int min = 2;
        // maximum to minimum
        for (int i = 0; i < n;)
        {
            if (i < n)
            {
                cout << max << " ";
                max -= 2;
                i++;
            }
            if (i < n)
            {
                cout << min << " ";
                min += 2;
                i++;
            }
        }
        cout << endl;
        max = (2 * n) - 1;
        min = 1;
        // minimum to maximum
        for (int i = 0; i < n;)
        {
            if (i < n)
            {
                cout << min << " ";
                min += 2;
                i++;
 
            }
            if(i==1){
                cout<<n+1<<" ";
                i++;
                max-=2;
                continue;
            }
            if(i==n-1){
                cout<<2*n-1;
                i++;
                max-=2;
                continue;
            }
            if (i < n)
            {
                cout << max << " ";
                max -= 2;
                i++;
            }
        }
        cout << endl;
    }
}