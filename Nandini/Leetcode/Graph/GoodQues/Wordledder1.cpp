#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) 
    {
        queue<pair<string,int> > q;
        q.push({startWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startWord);
        while(!q.empty())
        {
            int steps = q.front().second;
            string str = q.front().first;
            q.pop();
            if(str==targetWord)
                return steps;
            for(int i=0 ; i<str.size() ; i++)
            {
                char original = str[i];
                for(auto ch = 'a' ; ch<='z' ; ch++)
                {
                    str[i] = ch;
                    if(st.find(str) != st.end())
                    {
                        st.erase(str);
                        q.push({str,steps+1});
                    }
                }
                str[i] = original;
            }
        }
        return 0;
    }
};
