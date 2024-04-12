#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k ,ans=0;
        cin >> n >> k;
        string str;
        cin >> str;
        vector<int> v1(26,0),v2(26,0);
        for(int i=0 ; i<n ; i++)
        {
            if(str[i]>='a' && str[i]<='z')
            v1[str[i]-97]++;
            else 
            v2[str[i]-65]++;
        }
        for(int i=0 ;i <26 ; i++)
        {
            ans+=min(v1[i],v2[i]);
            int c= abs(v1[i]-v2[i]);
            while(k>0 && c>1)
            {
                c-=2;
                ans++;
                k--;
            }
        }
        cout << ans << endl;
    }
}