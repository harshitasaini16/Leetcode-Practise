class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        int s=0;
        for(int i=0;i<in.size();i++){
            bool f=false;
            for(int j=0;j<in.size();j++){
                if(i!=j){
                    if(in[i][0]>=in[j][0] && in[i][1]<=in[j][1]){
                        f=true;
                        break;
                    }
                }
            }
            if(f==false){
                s++;
            }
        }
        return s;
    }
};