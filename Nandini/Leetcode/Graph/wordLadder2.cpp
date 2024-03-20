#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> st(wordList.begin(),wordList.end());
        vector<string> usedOnLevel;
        int level = 0;
        usedOnLevel.push_back(beginWord);
        vector<vector<string>> ans;
        while(!q.empty())
        {
            vector<string> v = q.front();
            q.pop();
            
            // Erase previous level words
            if(v.size() > level)
            {
                level++;
                for(auto it : usedOnLevel)
                {
                    st.erase(it);
                }
            }
        
            string word = v.back();
            if(word == endWord)
            {
                if(ans.empty())
                    ans.push_back(v);
                else if(ans[0].size() == v.size())
                    ans.push_back(v);
            }
            for(int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for(auto ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if(st.count(word) > 0)
                    {
                        v.push_back(word);
                        q.push(v);
                        usedOnLevel.push_back(word);
                        v.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        
        return ans;
    }
};