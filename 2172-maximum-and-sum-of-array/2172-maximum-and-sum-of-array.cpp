class Solution {
public:
    map<vector<int>,int>dp;
    int fun(int x,vector<int>& nums,vector<int>v){
        if(x>=nums.size()){
            return 0;
        }
        if(dp.find(v)!=dp.end()){
            return dp[v];
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]>0){
                v[i]--;
                int temp=(nums[x]&(i+1))+fun(x+1,nums,v);
                ans=max(ans,temp);
                v[i]++;
            }
        }
        return dp[v]=ans;
    }
    int maximumANDSum(vector<int>& nums, int n) {
        dp.clear();
        vector<int>v(n,2);
        return fun(0,nums,v);
    }
};