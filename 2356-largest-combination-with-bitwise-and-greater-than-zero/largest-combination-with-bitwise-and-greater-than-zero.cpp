class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int max_cnt = 0;
        vector<int> bits(32, 0);

        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int num : candidates) {
                if (num & (1 << i))
                    cnt++;
            }
            max_cnt = max(max_cnt, cnt);
        }
        
        return max_cnt;
    }
};