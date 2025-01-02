class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int j = 0;
        int n = s.size();
        while (j < n) {
            while (j < n && s[j] == ' ')
                j++;
            string temp = "";
            while (j < n && s[j] != ' ') {
                temp += s[j];
                j++;
            }
            if (!temp.empty()) {
                if (!ans.empty())
                    ans = temp + " " + ans;
                else
                    ans = temp;
            }
        }

        return ans;
    }
};