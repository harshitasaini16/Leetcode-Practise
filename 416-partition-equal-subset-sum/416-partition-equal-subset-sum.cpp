class Solution {
public:
    int dp[201][10001];
    bool fun(int n,vector<int>& nums,int x){
        if(x==0){
            return true;
        }
        if(dp[n][x]!=-1){
            return dp[n][x];
        }
        if(n<=0){
            return false;
        }
        if(nums[n-1]<=x){
            return dp[n][x]=(fun(n-1,nums,x) || fun(n-1,nums,x-nums[n-1]));
        }
        else{
            return dp[n][x]=fun(n-1,nums,x);
        }
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        if(s%2!=0){
            return false;
        }
        return fun(nums.size()-1,nums,s/2);
    }
};