class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> broken(26, 0);

        for (char c : brokenLetters)
            broken[c - 'a']++;

        stringstream s(text);
        string word;
        int cnt = 0;

        while (s >> word) {
            bool notBroken = 1;

            for (char c : word) {
                if (broken[c - 'a']) {
                    notBroken = 0;
                    break;
                }
            }

            if (notBroken)
                cnt++;
        }

        return cnt;
    }
};