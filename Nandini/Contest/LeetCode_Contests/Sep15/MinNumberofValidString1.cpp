#include<bits/stdc++.h>
using namespace std;
class TrieNode{
        public : 
        TrieNode * ch[26];
        bool isEnd;
        TrieNode()
        {
           for(int i=0 ; i<=25 ;i ++)
           {
            ch[i] = NULL;
           }
           isEnd = false;
        }
    };
class Solution {
public:
    int dp[10001];
    class Trie{
        public : 
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        TrieNode* getRoot(){
            return root;
        }

        void insert(string &s)
        {
            int n = s.size();
            TrieNode*t = root;
            for(int i=0 ;i<n ; i++)
            {
                int k = s[i]-'a';
                if(t->ch[k]==NULL)
                  t->ch[k] = new TrieNode();
                t = t->ch[k];  
            }
            t->isEnd = true;
        }

        int search(string &s,int i,int n,int dp[])
        {
            if(i==n) return 0;
            if(dp[i]!=-1) return dp[i];

            int ans = 1e6;
            TrieNode *h = root;
            for(int j=i ; j<n ; j++)
            {
                int k = s[j]-'a';
                if(h->ch[k] != NULL){
                    ans = min(ans,1+search(s,j+1,n,dp));
                    h = h->ch[k];
                }
                else break;
            }
            return dp[i] = ans;
        }
    };
    int minValidStrings(vector<string>& words, string s) 
    {
        Trie trie;
        for(auto i: words)
        {
            trie.insert(i);
        }
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int k = trie.search(s,0,n,dp);
        if(k>1e4) return -1;
        return k;
    }
};