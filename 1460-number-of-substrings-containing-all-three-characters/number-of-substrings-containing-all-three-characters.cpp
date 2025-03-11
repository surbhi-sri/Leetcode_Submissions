class Solution {
public:
    int numberOfSubstrings(string s) {

     int n=s.size(), j=0;

     unordered_map<char, int> mp;
     int cnt=0;

     for(int i=0; i<n; i++){
        mp[s[i]]++;

        while(mp.size()==3 && j<i){
         cnt+=n-i;
         mp[s[j]]--;
         if(mp[s[j]]==0) mp.erase(s[j]);
         j++;
        }
     }   
      return cnt;
    }
};