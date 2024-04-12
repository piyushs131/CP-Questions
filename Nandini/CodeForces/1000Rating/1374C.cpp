#include <bits/stdc++.h>
using namespace std;
int main()
{    
   int t,n;
   cin >> t;
   while(t--)
   {
     cin >> n;
     string s;
     cin >> s;
     stack<char> st;
     for(int i=0 ; i<n ; i++)
     {
        if(st.empty()) st.push(s[i]);
        else if(st.top()=='(' && s[i]==')') st.pop();
        else st.push(s[i]);
     }
     cout << st.size()/2 << endl;
   }   
}