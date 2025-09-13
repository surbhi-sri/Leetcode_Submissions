class Solution {
public:
    int maxFreqSum(string s) {
        int mxv=0, mxc=0;
        vector<int> letters(26, 0);

        for(char c:s){
           if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            letters[c-'a']++;
            mxv=max(mxv, letters[c-'a']);
           }else{
             letters[c-'a']++;
            mxc=max(mxc, letters[c-'a']);
           } 
        }
      
         return (mxv+mxc);
    }
};