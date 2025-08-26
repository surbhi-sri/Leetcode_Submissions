class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_dig2=0;
        int area=0;

        for(auto it: dimensions){
            int l=it[0];
            int w=it[1];

            if(l*l+w*w>max_dig2){
                max_dig2=l*l+w*w;
                area=l*w;
            }else  if(l*l+w*w==max_dig2)
                area=max(area, l*w);
            else continue;
        }

        return area;
    }
};