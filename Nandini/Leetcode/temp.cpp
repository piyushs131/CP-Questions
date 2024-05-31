#include<bits/stdc++.h>
using namespace std;
int findingMinimumCOst(vector<int> &days,vector<int> cost,int ind,vector<vector<int>> dp,int cost)
{
    if(i==a.size() && j==b.size() && k==c.size())
    return true;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    if(c[k]==a[i])
    {
        return findingMinimumCOst(i+1,j,k+1,a,b,c,dp);
    }
    else if()


}
bool stringCheck(string a,string b,string c)
{
    vector<vector<vector<int> > > dp(a.size(),vector<vector<int> > (b.size(),vector<int> (c.size(),-1)));
    vector<vector<int> > dp2(a.size(),vector<int> (b.size(),-1));
}
int main()
{
    string a,b,c;
    cout << "ENter string a";
    cin >> a >> b >> c;
    if(stringCheck(a,b,c))
    cout << "Valid";
    else 
    cout << "INvalid;"
}