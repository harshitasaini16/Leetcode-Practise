class Solution {
public:
    int dp[1001][201];
    int fun(int target,vector<int>&nums,int n){
        if(target<0){
            return 0;
        }
        if(dp[target][n]!=-1){
            return dp[target][n];
        }
        if(target==0){
            return 1;
        }
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=fun(target-nums[i],nums,n);
        }
        return dp[target][n]=s;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return fun(target,nums,nums.size());
    }
};