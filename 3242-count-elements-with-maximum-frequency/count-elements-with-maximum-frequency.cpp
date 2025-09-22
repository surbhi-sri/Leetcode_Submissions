class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int sum = 0;
        int max_freq = 0;

        vector<int> freq(101, 0);

        for (int num : nums) {
            freq[num]++;

            if (freq[num] > max_freq) {
                max_freq = freq[num];
                sum = max_freq;
            } else if (freq[num] == max_freq) {
                sum += max_freq;
            }
        }

        return sum;
    }
};