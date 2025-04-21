class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();

        vector<int> arr(n);

        int xorr=0;

        for(int i=0; i<n; i++){
         int new_arr=xorr^pref[i];
         arr[i]=new_arr;
         xorr^=new_arr;
        }

        return arr;
    }
};