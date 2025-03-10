class Solution {
public:
    bool isVowel(char& ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return 1;
        return 0;
    }

    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int> mp;

        int n = word.size();

        vector<int> nextCons(n);
        int lastCons = n;

        for (int i = n - 1; i >= 0; i--) {
            nextCons[i] = lastCons;

            if (!isVowel(word[i]))
                lastCons = i;
        }

        int i = 0;
        int j = 0;
        long long count = 0;

        int cons = 0;

        while (j < n) {
            char ch = word[j];

            if (isVowel(ch))
                mp[ch]++;
            else
                cons++;

            while (i< n && cons > k) {
                char ch = word[i];
                if (isVowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0)
                        mp.erase(ch);
                } else
                    cons--;

                    i++;
            }

            while (i< n && mp.size() == 5 && cons == k) {
                int idx = nextCons[j];
                count += idx - j;

                char ch = word[i];
                if (isVowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0)
                        mp.erase(ch);
                } else
                    cons--;

                    i++;
            }

            j++;
        }

        return count;
    }
};