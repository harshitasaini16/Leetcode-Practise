class Solution {
public:
    map<pair<int,int>,int>dp;
    int fun(int n,vector<int>& nums, int target){
        if(n==0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(dp.find({n,target})!=dp.end()){
            return dp[{n,target}];
        }
        return dp[{n,target}]=fun(n-1,nums,target+nums[n-1])+fun(n-1,nums,target-nums[n-1]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return fun(nums.size(),nums,target);
    }
};