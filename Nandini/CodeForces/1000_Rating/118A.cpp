#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public :
    string resString(string str)
    {
        int n = str.size();
        string ans="";
        for(int i=0 ; i<n ;i ++)
        {
           if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='U' || str[i]=='Y' || str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='u' || str[i]=='y' || str[i]=='o' || str[i]=='O')
           {
             continue;
           }
           else if(str[i]>=97 && str[i]<=122)
           {
             ans+='.';
             ans+=str[i];
           }
           else
           {
             ans+='.';
             ans+= str[i]+32;
           }
        }
        return ans;
    }
};
int main()
{
    string str;
    cin>> str;
    Solution obj;
    cout << obj.resString(str);
}