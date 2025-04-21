class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int setbits = __builtin_popcount(arr[i]);
            pq.push({setbits, arr[i]});
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};