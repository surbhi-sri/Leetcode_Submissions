class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> pos(26, -1);

        int n = s.size();

        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'] = i;
        }

        int i = 0, j = 0;

        int farthest = pos[s[i] - 'a'];

        vector<int> ans;

        while (i < n && j < n) {

            while (j <= farthest) {
                if (pos[s[j] - 'a'] > farthest)
                    farthest = pos[s[j] - 'a'];

                j++;
            }
            ans.push_back(j - i);
            i = j;
            if(j<n)
            farthest = pos[s[j] - 'a'];
        }

        return ans;
    }
};