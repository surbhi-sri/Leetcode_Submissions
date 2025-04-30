class Solution {
public:
     

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(int num: arr1){
            while(!st.count(num) && num>0){
                st.insert(num);
                num /=10;
            }
        }

        int res=0;
         
        for(int num: arr2){
            while(!st.count(num) && num>0)
                num /=10;
            
            if(num>0)
            res= max(res, static_cast<int>(log10(num)+1));
        }

        return res;
    }
};