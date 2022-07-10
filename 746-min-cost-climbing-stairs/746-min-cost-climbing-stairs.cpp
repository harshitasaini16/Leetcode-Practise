class Solution {
public:
    int dp[1001];
    int fun(int x,vector<int>& cost){
        if(x>=cost.size()){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int ans1=fun(x+1,cost);
        int ans2=fun(x+2,cost);
        return dp[x]=cost[x]+min(ans1,ans2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(fun(0,cost),fun(1,cost));
    }
};