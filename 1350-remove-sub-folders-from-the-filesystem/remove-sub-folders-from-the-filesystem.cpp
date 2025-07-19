class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string current_folder = folder[i];
            string last_folder = ans.back() + '/';

            if (current_folder.find(last_folder) != 0)
                ans.push_back(current_folder);
        }

        return ans;
    }
};