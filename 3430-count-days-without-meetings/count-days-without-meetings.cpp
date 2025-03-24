class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
      sort(meetings.begin(), meetings.end());

        int e=0, cnt=0;
        int n=meetings.size();

        for(int i=0; i<n; i++){
         int gap=(meetings[i][0]-e-1);
         e=max(e, meetings[i][1]);
         if(gap>0) cnt+=gap;
        }

         int gap=(days-e);
         if(gap>0) cnt+=gap;

         return cnt;
    }
};