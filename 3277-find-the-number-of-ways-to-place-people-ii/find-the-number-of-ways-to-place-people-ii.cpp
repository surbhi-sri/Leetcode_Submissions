class Solution {
public:

 static bool CustomSort(const vector<int>&a , const vector<int>&b){
      if(a[0]==b[0])return a[1]>b[1];
      return a[0] < b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
      sort(points.begin(),points.end(),CustomSort);

        int n = points.size();
        int ans =0;
        for(int i =0 ;i<n-1;i++){
            int limit =INT_MIN;
            int x = points[i][0];
            int y = points[i][1];
            for(int j=i+1 ;j<n;j++){
                int nx = points[j][0];
                int ny = points[j][1];
                if(ny <= y && ny > limit){
                    ans++;
                    limit = ny;
                }
            }
        }
        return ans;   
    }
};