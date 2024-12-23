#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string,int> > q;
        q.push({beginWord,1});
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        while(!q.empty())
        {
            string tp = q.front().first;
            int num = q.front().second;
            q.pop();
            for(int i=0 ; i<tp.size() ; i++)
            {
                char org = tp[i];
                for(char ch = 'a' ; ch<='z' ; ch++)
                {
                    tp[i] = ch;
                    if(s.find(tp)!=s.end())
                    {
                        if(tp==endWord)
                    {
                        return num+1;
                    }
                        q.push({tp,num+1});
                        s.erase(tp);
                    }
                }
                tp[i] = org;
            }
        }
        return 0;
    }
};