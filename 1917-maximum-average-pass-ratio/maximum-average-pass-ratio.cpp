class Solution {
public:
#define p pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<p> pq;

        for (int j = 0; j < n; j++) {
            double ratio0 = (double)classes[j][0] / classes[j][1];
            double ratio1 = (double)(classes[j][0] + 1) / (classes[j][1] + 1);
            double rise = ratio1 - ratio0;

            pq.push({rise, j});
        }

        for (int i = 0; i < extraStudents; i++) {
            double max_rise = pq.top().first;
            int rise_ind = pq.top().second;
            pq.pop();

            classes[rise_ind][0] += 1;
            classes[rise_ind][1] += 1;

            double ratio0 = (double)classes[rise_ind][0] / classes[rise_ind][1];
            double ratio1 = (double)(classes[rise_ind][0] + 1) / (classes[rise_ind][1] + 1);
            double rise = ratio1 - ratio0;

            pq.push({rise, rise_ind});
        }

        double total_ratio = 0.0;
        for (int i = 0; i < n; i++)
            total_ratio += (double)classes[i][0] / classes[i][1];

        return (total_ratio / n);
    }
};