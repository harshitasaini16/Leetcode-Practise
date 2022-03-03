class Solution {
public:
    map<pair<int,int>,int>dp;
    bool fun(vector<int>& nums,int n,int s){
        if(s==0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(dp.find({n,s})!=dp.end()){
            return dp[{n,s}];
        }
        if(nums[n-1]<=s){
            return dp[{n,s}]=(fun(nums,n-1,s-nums[n-1]) || fun(nums,n-1,s));
        }
        return dp[{n,s}]=fun(nums,n-1,s);
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        dp.clear();
        if(s%2!=0){
            return false;
        }
        return fun(nums,nums.size(),s/2);
    }
};