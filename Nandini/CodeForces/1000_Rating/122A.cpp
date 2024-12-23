#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool lucky(int n)
    {
        vector<int> arr{4,7,44,77,447,774,474,747,444,777,47,74,477};
        for(int i=0 ; i<arr.size() ; i++)
        {
            if(n%arr[i]==0)
            return true;
        }
        return false;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution obj;
    if (obj.lucky(n))
        cout << "YES";
    else
        cout << "NO";
}