class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                if (words[j].size() >= words[i].size()) {
                    string s1 = words[i];
                    string s2 = words[j];
                    int len = s1.size();

                    if (s1 == s2.substr(0, len) &&
                        s1 == s2.substr(s2.length() - len))
                        cnt++;
                }
            }
        }
        return cnt;
    }
};