class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b){
                 return a[1] > b[1];
             });

        int i = 0;
        int n = boxTypes.size();
        int mxunit = 0;

        while (truckSize > 0 && i<n) {
            if (truckSize >= boxTypes[i][0]) {
                mxunit += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                mxunit += truckSize * boxTypes[i][1];
                break;
            }
            i++;
        }

        return mxunit;
    }
};