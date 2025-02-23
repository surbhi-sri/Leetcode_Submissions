class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> degree(n,0);
        vector<vector<int>> adj(n);
        int p=prerequisites.size();
        
        for(int i=0; i<p; i++) {
            degree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int> q;
        
        for(int i=0; i<n; i++){
            if(degree[i]==0) q.push(i); 
        }
        
         vector<int> ans;

        while(!q.empty()){
         int node=q.front();
         q.pop();
         
         ans.push_back(node);
         
         for(auto it: adj[node]){
             degree[it]--;
             if(degree[it]==0) q.push(it);
         }
        }
        
      //  reverse(ans.begin(), ans.end());

      if(ans.size()==n) return ans;
        return {};
    }
};