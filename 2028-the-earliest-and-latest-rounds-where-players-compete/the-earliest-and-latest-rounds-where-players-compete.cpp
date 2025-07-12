class Solution {

 pair<int, int> backtracking(int left, int middle, int right){
        if(left == right) return {1, 1}; // done
        if(left > right) return {INT_MAX/2, 0}; // already done before
        // left always smaller that right
        int resMin = INT_MAX/2;
        int resMax = 0;
        int newN = (left + middle + right + 3) / 2  - 2;
        // new left can be 0-left
        // new middle can be minMid ~ maxMid
        int minMid = max(0, (left + middle - right + 1) / 2);
        int maxMid = min(middle, (middle + right - left - 1) / 2);
        for(int newLeft = 0; newLeft <= left; ++newLeft){
            for(int newMid = minMid; newMid <= maxMid; ++newMid){
                int newR = newN - newLeft - newMid;
                auto [subMin, subMax] = backtracking(newLeft, newMid, newR);
                resMin = min(resMin, subMin+1);
                resMax = max(resMax, subMax+1);
            }
        }
        return {resMin, resMax};
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
            int left = firstPlayer - 1;
        int right = n - secondPlayer;
        int middle = secondPlayer - firstPlayer - 1;
        if(left > right) swap(left, right);
        pair<int, int> res = backtracking(left, middle, right);
        return {res.first, res.second};
    }
};