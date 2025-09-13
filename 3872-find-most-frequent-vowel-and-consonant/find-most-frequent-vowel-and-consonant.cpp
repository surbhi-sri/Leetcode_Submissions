class Solution {
public:
    int maxFreqSum(string s) {
        int cnt[26] = {0};
        for (char c : s)
            cnt[c - 'a']++;
        auto isVowel = [](int i) {
            return i == 0 || i == 4 || i == 8 || i == 14 || i == 20;
        };
        int maxVowel = 0, maxConsonant = 0;
        for (int i = 0; i < 26; ++i) {
            if (isVowel(i)) 
                maxVowel = max(maxVowel, cnt[i]);
            else 
                maxConsonant = max(maxConsonant, cnt[i]);
        }
        return maxVowel + maxConsonant;
    }
};