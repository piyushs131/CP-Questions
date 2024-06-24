#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool hello(string s)
    {
        string h = "hello";
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == h[j])
            {
                j++;
            }
        }
        if(j>=h.size())return true;
        return false;
    }
};
int main()
{
    string str;
    cin >> str;
    Solution obj;
    if (obj.hello(str))
        cout << "YES";
    else
        cout << "NO";
}