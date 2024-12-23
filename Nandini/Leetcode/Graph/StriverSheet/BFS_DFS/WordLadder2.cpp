#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (wordSet.find(endWord) == wordSet.end()) return result;
        
        unordered_map<string, vector<string>> predecessors;
        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(beginWord);
        bool found = false;

        while (!currentLevel.empty() && !found) {
            for (const string& word : currentLevel) {
                wordSet.erase(word);
            }

            for (const string& word : currentLevel) {
                string currentWord = word;
                for (int i = 0; i < currentWord.size(); ++i) {
                    char originalChar = currentWord[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        currentWord[i] = ch;
                        if (wordSet.find(currentWord) != wordSet.end()) {
                            nextLevel.insert(currentWord);
                            predecessors[currentWord].push_back(word);
                            if (currentWord == endWord) found = true;
                        }
                    }
                    currentWord[i] = originalChar;
                }
            }

            if (found) break;
            currentLevel.swap(nextLevel);
            nextLevel.clear();
        }

        if (found) {
            vector<string> path;
            backtrack(result, path, predecessors, endWord, beginWord);
        }

        return result;
    }

private:
    void backtrack(vector<vector<string>>& result, vector<string>& path, unordered_map<string, vector<string>>& predecessors, string word, string& beginWord) {
        path.push_back(word);
        if (word == beginWord) {
            result.push_back(vector<string>(path.rbegin(), path.rend()));
        } else {
            for (const string& pred : predecessors[word]) {
                backtrack(result, path, predecessors, pred, beginWord);
            }
        }
        path.pop_back();
    }
};
