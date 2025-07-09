class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;
        int e = 0;

        for(int i = 0; i <= n; i++) {
            if(i==0 && e==startTime[i]){
                e=endTime[i];
                continue;
            }
            if (i == n) {
                    freeTime.push_back(eventTime - e);
 //                     cout<<freeTime.back()<<" ";
                break;
            }   
              freeTime.push_back(startTime[i] - e);
              e = endTime[i];
//              cout<<freeTime.back()<<" ";
        }

         int  time=0;
         n=freeTime.size();
        
         for(int i=0; i<min(n , k+1); i++){
            time+=freeTime[i];
         }

        //  cout<<time<<" ";

         if(n<= k+1) return time;
         int maxT=time;
         int i=0;

         for(int j=k+1; j<n; j++, i++){
           time +=(freeTime[j]-freeTime[i]);
           maxT=max(maxT, time);
            // cout<<time<<" ";
         }

         return maxT;
    }
};