class Solution {
public:
   
   typedef unsigned long long ull;

    int mostBooked(int n, vector<vector<int>>& meetings) {
         if(n==1) return 0;

        sort(meetings.begin(), meetings.end());
        unordered_map<ull, ull> mp;
        priority_queue<pair<ull, ull>, vector<pair<ull, ull>>, greater<pair<ull, ull>>> pq;
        priority_queue<ull, vector<ull>, greater<ull>> room;


        for(int i=0; i<n; i++) 
           room.push(i);

        ull ans=0;


        for(int i=0; i<meetings.size(); i++){
            ull s = meetings[i][0];
            ull e = meetings[i][1];

            while(!pq.empty() && s>=pq.top().first) {
                room.push(pq.top().second);
                pq.pop();
            }

             if(pq.size()<n){
              mp[room.top()]++;
              pq.push({e, room.top()});
              room.pop();
             }else{
                int delay=pq.top().first-s;
                int room=pq.top().second;
                pq.pop();
                mp[room]++;
                pq.push({e+delay, room});
             }
        }

         for(int i=0; i<n; i++) {
            if(mp[i]>mp[ans]) ans=i;
         }

         return ans;
    }
};