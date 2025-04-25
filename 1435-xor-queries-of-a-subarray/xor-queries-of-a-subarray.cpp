class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] ^ arr[i];

        int qn=queries.size();

        vector<int> ans;
        for(int i=0; i<qn; i++){
            int l=queries[i][0];
            int r=queries[i][1];

            int xorrq= prefix[r+1]^prefix[l];
            ans.push_back(xorrq);
        }

        return ans;
    }
};