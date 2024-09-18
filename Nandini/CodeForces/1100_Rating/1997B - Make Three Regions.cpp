#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isThere3Dots(int r,int c,vector<vector<char> > &v)
{
   int dots=0;
   if(r-1>=0 && v[r-1][c]=='.') dots++;
   if(r+1<=1 && v[r+1][c]=='.') dots++;
   if(c-1>=0 && v[r][c-1]=='.') dots++;
   if(c+1<v[0].size() && v[r][c+1]=='.') dots++;

   return dots==3?true:false;
}

bool threeBlocks(int r,int c,vector<vector<char> > &v)
{
    int delr[4] = {-1,-1,1,1};
    int delc[4] = {-1,1,1,-1};
    int countX=0;
    for(int i=0 ;i <4 ; i++)
    {
        int newr = delr[i] + r;
        int newc = delc[i] + c;
        if(newr>=0 && newc>=0 && newr<2 && newc<v[0].size() && v[newr][newc]=='x')
        countX++;
    }
    return countX>=2?true:false;
}
void solve() {
   ll n;
   cin >> n;
   vector<vector<char> > v(2,vector<char> (n,'.'));
   for(int i=0 ;i <2 ; i++)
   {
    for(int j=0 ;j <n ; j++)
    {
        cin >> v[i][j];
    }
   }

   int ans =0;
   for(int i=0 ; i<2 ; i++)
   {
    for(int j=0 ; j<n ;j ++)
    {
        if(v[i][j]=='.' && isThere3Dots(i,j,v) && threeBlocks(i,j,v))
        {
          ans++;
        }
    }
   }
   cout << ans <<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    // solve();
    return 0;
}
