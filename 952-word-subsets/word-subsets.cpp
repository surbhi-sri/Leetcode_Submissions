class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<char> freq(26, 0);
        for (const string& word : words2) {
            vector<char> mfreq(26, 0);
            for (char ch : word){
                mfreq[ch - 'a']++;
                freq[ch-'a'] = max(freq[ch-'a'], mfreq[ch-'a']);
            }
        }

        vector<string> ans;

        for (const string& word : words1) {
            vector<char> mfreq(26, 0);
            int flag = 1;
            for (char ch : word)
                mfreq[ch - 'a']++;

            for (int i = 0; i < 26; i++) {
                if (freq[i] > mfreq[i])
                    flag = 0;
            }

            if (flag)
                ans.push_back(word);
        }
        return ans;
    }
};