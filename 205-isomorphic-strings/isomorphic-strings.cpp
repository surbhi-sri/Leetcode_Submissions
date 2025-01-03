class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp;
        map<char, char> mpt;
        int n = s.size();
        if (n == 1)
            return 1;
        for (int i = 0; i < n; i++){
            if (mp.find(s[i]) != mp.end() || mpt.find(t[i]) != mpt.end()) {
                if (mp[s[i]] != t[i] || mpt[t[i]] != s[i])
                    return 0;
            }
            mp[s[i]] = t[i];
            mpt[t[i]] = s[i];
        }
        return 1;
    }
};