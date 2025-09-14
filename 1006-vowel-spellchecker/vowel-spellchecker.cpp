class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_map<string, int> mp1, mp2, mp3;
        int n = wordlist.size();

        for (int i = 0; i < n; i++) {
            mp1[wordlist[i]] = i;
            string str1, str2;

            for (char ch : wordlist[i]) {
                char c=tolower(ch);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    str1 += tolower(c);
                    str2 += '*';
                } else {
                    str1 += tolower(c);
                    str2 += tolower(c);
                }
            }
            if (mp2.find(str1) == mp2.end())
                mp2[str1] = i;
            if (mp3.find(str2) == mp3.end())
                mp3[str2] = i;
        }

        int m = queries.size();

        vector<string> ans(m);

        for (int i = 0; i < m; i++) {
            if (mp1.find(queries[i]) != mp1.end())
                ans[i] = wordlist[mp1[queries[i]]];
            else {

                string str1, str2;

                for (char ch : queries[i]) { 
                    char c=tolower(ch);
                    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' ||
                        c == 'u') {
                        str1 += tolower(c);
                        str2 += '*';
                    } else {
                        str1 += tolower(c);
                        str2 += tolower(c);
                    }
                }
                if (mp2.find(str1) != mp2.end())
                    ans[i] = wordlist[mp2[str1]];
                else if (mp3.find(str2) != mp3.end())
                    ans[i] = wordlist[mp3[str2]];
                else
                    ans[i] = "";
            }
        }
        return ans;
    }
};