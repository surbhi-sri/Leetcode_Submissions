class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>sad_user;

        for(auto &friends: friendships){
            int u=friends[0]-1;
            int v=friends[1]-1;

            unordered_set<int> lang_st(languages[u].begin(), languages[u].end());
            int present=0;
            for(auto lang: languages[v]){
                if(lang_st.find(lang)!=lang_st.end()){
                    present=1;
                    break;
                }
            }

            if(!present){
                sad_user.insert(u);
                sad_user.insert(v);
            }
        }

        int max_lang=0;
        unordered_map<int, int> lang_freq;

        for(int user: sad_user){
           for(auto lang: languages[user]){
              lang_freq[lang]++;
               max_lang=max(lang_freq[lang],max_lang);
           }
        }

        return sad_user.size()-max_lang;
    }
};