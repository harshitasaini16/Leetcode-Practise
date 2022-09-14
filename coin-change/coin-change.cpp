class Solution {
public:
    int dp[13][10001];
    int fun(int x,vector<int>& coins,int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX-1;
        }
        if(x>=coins.size()){
            return INT_MAX-1;
        }
        if(dp[x][amount]!=-1){
            return dp[x][amount];
        }
        return dp[x][amount]=min(1+fun(x,coins,amount-coins[x]),fun(x+1,coins,amount));
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        sort(coins.begin(),coins.end());
        int x=fun(0,coins,amount);
        if(x>=INT_MAX-1){
            return -1;
        }
        return x;
    }
};