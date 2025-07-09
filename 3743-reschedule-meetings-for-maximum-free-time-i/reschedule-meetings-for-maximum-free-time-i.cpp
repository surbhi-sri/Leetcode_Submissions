class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;

        freeTime.push_back(startTime[0] - 0);

        for (int i = 1; i < n; i++)
            freeTime.push_back(startTime[i] - endTime[i - 1]);

        freeTime.push_back(eventTime - endTime[n - 1]);

        int time = 0;
        n = freeTime.size();

        for (int i = 0; i < min(n, k + 1); i++) {
            time += freeTime[i];
        }

        if (n <= k + 1)
            return time;

        int maxT = time;
        int i = 0;

        for (int j = k + 1; j < n; j++, i++) {
            time += (freeTime[j] - freeTime[i]);
            maxT = max(maxT, time);
            // cout<<time<<" ";
        }

        return maxT;
    }
};