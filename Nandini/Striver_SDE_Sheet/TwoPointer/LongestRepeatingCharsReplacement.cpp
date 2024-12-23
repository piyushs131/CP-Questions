#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n = s.size();
        int maxLen = 0, maxFreq = 0, l = 0;
        vector<int> hash(26, 0);

        for (int r = 0; r < n; r++) 
        {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            
            if ((r - l + 1) - maxFreq > k) 
            {
                hash[s[l] - 'A']--;
                l++;
            }

            // The window size is r - l + 1
            maxLen = max(maxLen, r - l + 1);
        }
        
        return maxLen;
    }
};
