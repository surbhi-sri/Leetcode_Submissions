class Solution {
public:
    vector<int> sumZero(int n) {
          vector<int> result(n,0);
        for(int i=0;i<n/2;i++){
            result[2*i] = i+1;
            result[2*i+1] = -i-1;
        }
        return result;
    }
};