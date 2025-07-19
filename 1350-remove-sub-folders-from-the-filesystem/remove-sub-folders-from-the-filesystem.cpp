class Solution {
public:
      bool prefixCheck(string& str, string& folder) {
        int n = str.length(), m = folder.length();
        if (m <= n) return false;

        int i = 0;
        while (i < n) {
            if (str[i] != folder[i])
                return false;
            i++;
        }

        return folder[i] == '/';
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;

        int i = 0, n = folder.size();
        while (i < n) {
            string str = folder[i];
            ans.push_back(str);
            i++;
            while (i < n && prefixCheck(str, folder[i])) {
                i++; // skip subfolders
            }
        }
        return ans;
        
    }
};