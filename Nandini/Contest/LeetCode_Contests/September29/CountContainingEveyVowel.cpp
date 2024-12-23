#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
 bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    long long countOfSubstrings(string word, int k) 
    {
        long long n = word.size();
        if (n < k + 5)
            return 0;

        long long l = 0, u = 0;
        long long vowel = 0, conso = 0;
        unordered_map<char, long long> mp;
        long long ans = 0, last_conso_index=-1;
        while (u < n) {
            if (isVowel(word[u])) {
                if (mp[word[u]] == 0) {
                    vowel++;
                }
                mp[word[u]]++;
            } else {
                mp[word[u]]++;
                conso++;
            }

            while (conso > k) {
                if (!isVowel(word[l]))
                {
                    conso--;
                    last_conso_index = l;
                    mp[word[l]]--;
                }
                else {
                    mp[word[l]]--;
                    if (mp[word[l]] == 0)
                        vowel--;    
                }
                l++;
            }

            while(conso==k && isVowel(word[l]) && mp[word[l]]>1)
            {
                mp[word[l]]--;
                l++;
            }
            if (vowel == 5 && conso == k) 
            {
                //cout << "l=" << l << ",u=" << u << endl;
                ans+= (l-last_conso_index);
            }
            u++;
        }
        return ans;  
    }
};