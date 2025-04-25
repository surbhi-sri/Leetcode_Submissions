class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;

        unordered_map<int, int> mp, total;
        int xorr = 0;
        mp[xorr] = -1;
        total[xorr] = 1;

        for (int i = 0; i < n; i++) {
            xorr ^= arr[i];
            if (mp.find(xorr) != mp.end()) {
                cnt += total[xorr]* (i - 1) - mp[xorr];
            }
            total[xorr]++;
            mp[xorr] = i + mp[xorr];
        }
        return cnt;
    }
};