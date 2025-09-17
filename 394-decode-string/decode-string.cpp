class Solution {
public:
    string decodeString(string s) {
        string ans;

        for (char c : s) {
            if (c != ']')
                ans.push_back(c);
            else {
                string word;

                while (ans.back() != '[') {
                    word.push_back(ans.back());
                    ans.pop_back();
                }

                ans.pop_back();
                string k;

                while (!ans.empty() && isdigit(ans.back())) {
                    k.push_back(ans.back());
                    ans.pop_back();
                }

                reverse(word.begin(), word.end());
                reverse(k.begin(), k.end());
                int num = stoi(k);

                string repeat;
                while (num--) {
                    repeat += word;
                }

                for (char ch : repeat)
                    ans.push_back(ch);
            }
        }
        return ans;
    }
};