class Solution {
public:
    int dp[201][20001];
    bool fun(int x,vector<int>& nums,int s){
        if(s==0){
            return true;
        }
        if(dp[x][s]!=-1){
            return dp[x][s];
        }
        if(x>=nums.size()){
            return dp[x][s]=false;
        }
        if(nums[x]>s){
            return dp[x][s]=fun(x+1,nums,s);
        }
        else{
            return dp[x][s]=(fun(x+1,nums,s) || fun(x+1,nums,s-nums[x]));
        }
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        if(s%2!=0){
            return false;
        }
        return fun(0,nums,s/2);
    }
};