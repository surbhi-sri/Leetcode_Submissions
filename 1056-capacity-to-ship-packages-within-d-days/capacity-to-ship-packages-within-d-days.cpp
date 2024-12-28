class Solution {
public:
   int no_of_days(vector<int>& weight, int n, int capacity, int days){
    int cnt=1, load=0;
    for(int i=0;i<n;i++){
   if(load+weight[i] > capacity){
    cnt+=1;
    load=weight[i];
   }else load += weight[i];

   if(cnt>days) return cnt;
    }
    return cnt;
   }

    int shipWithinDays(vector<int>& weight, int days) {
    int low=INT_MIN, high=0;
    int n=weight.size();
    for(int i=0;i<n;i++){
        low=max(weight[i], low);
        high +=weight[i];
    } 
    int ans=high;
    while(low<=high){
      int  mid=(low+high)/2;
        int day_no=no_of_days(weight, n, mid, days);
         if(day_no<=days){
            ans=min(ans,mid);
            high=mid-1;
         }else low=mid+1;
    }
    return ans; 
    }
};