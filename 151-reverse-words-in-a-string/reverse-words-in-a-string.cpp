class Solution {
public:
    string reverseWords(string s) {
        stringstream st(s);
        string ans, word;

        while (st >> word) {
            reverse(word.begin(), word.end());
            ans += word + ' ';
        }

        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};