class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        unordered_set<string> st;
        vector<string> ans;

        for(string &f:folder){
          string str="";
          int flag=1;
          for(int i=0; i<f.size(); i++){
            str =str+f[i];
            if(i<f.size() && f[i+1]=='/' && st.find(str)!=st.end()){
                flag=0;
                break;
            }
          }
           if(flag){
            ans.push_back(f);
            st.insert(f);
           }
        }

        return ans;
    }
};