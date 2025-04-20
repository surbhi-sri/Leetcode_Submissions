class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[answers[i]]++;

        int cnt = 0;

        for (auto& it : mp) {
            int rabits_cnt = it.first;
            int similarity_cnt = it.second;

            int total_sameRabit =
                (rabits_cnt + 1) * (similarity_cnt / (rabits_cnt + 1));

            if (similarity_cnt % (rabits_cnt + 1))
                total_sameRabit += rabits_cnt+1;

            cnt += total_sameRabit;
        }

        return cnt;
    }
};