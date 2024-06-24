#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        long long l=0,r=0,cost =0;
        cin >> s;
        for(int i=0 ; i<s.size()-1 ; i++)
        {
            if(s[i]<s[i+1])
            {
                r++;
                l=r;
            }
            else if(s[i]==s[i+1])
            {
                r++;
            }
            else 
            {
                r++;
                swap(s[l],s[r]);
                cost += r-l+1;
                l++;
            }
            // cout << "l=" << l << " ,r=" << r << " ,cost=" << cost << " ,s=" << s << endl;
        }
        cout << cost << endl;
    }
}