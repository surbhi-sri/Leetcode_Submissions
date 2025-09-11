class Solution {
public:
    bool IsVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }

        return false;
    }
    string sortVowels(string s) {
        vector<char> result(s.length(), '\0');
        vector<char> vowel;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (IsVowel(ch))
                vowel.push_back(ch);
            else
                result[i] = ch;
        }
        auto cmp = [](const char& a, const char& b) {
            return a > b; // descending order
        };

        sort(vowel.begin(), vowel.end(), cmp);

        if (vowel.empty())
            return s;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == '\0') {
                result[i] = vowel.back();
                vowel.pop_back();
            }
        }

        string ans(result.begin(), result.end());

        return ans;
    }
};