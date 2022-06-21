class Solution {
public:
    int dp[201][20001];
    bool fun(int x,vector<int>& nums,int s){
        if(s<0){
            return false;
        }
        if(s==0){
            return true;
        }
        if(x==nums.size()){
            return false;
        }
        if(dp[x][s]!=-1){
            return dp[x][s];
        }
        return dp[x][s]=(fun(x+1,nums,s-nums[x]) || fun(x+1,nums,s));
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        if(s%2!=0){
            return false;
        }
        return fun(0,nums,s/2);
    }
};