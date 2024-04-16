#include <bits/stdc++.h>
using namespace std;
bool canBeString(string s,char c,int &ind)
{
    bool flag = false;
    for(int i=0 ;i<ind ; i++)
    {
        if(s[i]==c)
        {
            flag = true;
            while(i+1<ind && s[i+1]==s[ind+1])
            {
                i++;
                ind++;
            }
        }
    }
    return flag;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n; 
        cin >> s;

        for(int i=0 ;i <s.size() ; i++)
        {
            if(n==0) break;
            if(canBeString(s,s[i],i)) 
            {
                n--;
            } 
            else 
            n--;
        }
        if(n==0)cout << "NO" << endl;
        else 
        cout << "YES" << endl;
    }
}