#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public :
    string findString(string s)
    {
        string ans = s;
        if(s[0]>=97 && s[0]<=122)
        s[0] = s[0]-32;
        else 
        s[0]+=32;

        for(int i=1 ; i<s.size() ; i++)
        {
            if(s[i]>=97 && s[i]<=122)
            return ans;

            s[i] = s[i]+32;
        }
        return s;
    }
};
int main()
{
    string s;
    cin >> s ;
    Solution obj;
    cout << obj.findString(s);
}