class Solution {
public:
    bool substring(string word, string sub) {
        int n = word.size();
        int m = sub.size();

        for (int i = 0; i < n - m + 1; i++) {
            if (word[i] == sub[0]) {
                int j1 = i;
                int j2 = 0;
                while (j1 < n && j2 < m && word[j1] == sub[j2]) {
                    j1++;
                    j2++;
                }
                if (j2 == m)
                    return 1;
            }
        }

        return 0;
    }

    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        vector<string> ans;
        int n=words.size();

         for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(substring(words[j], words[i])){
                    ans.push_back(words[i]);
                    break;
                }
            }
         }

         return ans;
    }
};