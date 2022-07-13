class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        if(v1[1]<v2[1]){
            return true;
        }
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        if(in.size()==0){
            return 0;
        }
        int ans=-1;
        sort(in.begin(),in.end(),cmp);
        vector<int>pre=in[0];
        for(vector<int>j : in){
            if(pre[1]>j[0]){
                ans++;
            }
            else{
                pre=j;
            }
        }
        return ans;
    }
};