class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> last_sennS(256, -1);
        vector<int> last_sennT(256, -1);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (last_sennS[s[i]] != last_sennT[t[i]])
                return 0;
            last_sennS[s[i]] = i;
            last_sennT[t[i]] = i;
        }
        return 1;
    }
};