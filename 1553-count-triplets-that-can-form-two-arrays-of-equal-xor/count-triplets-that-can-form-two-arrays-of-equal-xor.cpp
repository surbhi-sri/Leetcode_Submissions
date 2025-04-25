class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;

        unordered_map<int, vector<int>> mp;
        int xorr = 0;
        mp[xorr].push_back(-1);

        for (int i = 0; i < n; i++) {
            xorr ^= arr[i];
            if (mp.find(xorr) != mp.end()) {
                for (auto& ind : mp[xorr])
                    cnt += (i - ind - 1);
            }
            mp[xorr].push_back(i);
        }
        return cnt;
    }
};