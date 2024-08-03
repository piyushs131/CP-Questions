#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0); // Stores the last index of each character
        vector<bool> seen(26, false); // Tracks if a character is in the current result
        stack<char> st; // Stack to store the result characters

        // Populate the lastIndex array with the last position of each character in the string
        for (int i = 0; i < s.size(); ++i) {
            lastIndex[s[i] - 'a'] = i;
        }

        // Process each character in the string
        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];
            // If the character is already in the result, skip it
            if (seen[currentChar - 'a']) {
                continue;
            }
            
            // Remove characters from the stack if the current character is smaller and the removed character can still appear later
            while (!st.empty() && st.top() > currentChar && lastIndex[st.top() - 'a'] > i) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            // Add the current character to the stack and mark it as seen
            st.push(currentChar);
            seen[currentChar - 'a'] = true;
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
