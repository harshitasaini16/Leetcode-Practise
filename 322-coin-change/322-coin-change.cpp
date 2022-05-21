class Solution {
public:
    int dp[10001][13];
    int fun(int amount,vector<int>& coins,int x){
        if(amount==0){
            return 0;
        }
        if(x==0){
            return INT_MAX-1;
        }
        if(dp[amount][x]!=-1){
            return dp[amount][x];
        }
        if(coins[x-1]>amount){
            return dp[amount][x]=fun(amount,coins,x-1);
        }
        return dp[amount][x]=min(1+fun(amount-coins[x-1],coins,x),fun(amount,coins,x-1));
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        sort(coins.begin(),coins.end());
        int x=fun(amount,coins,coins.size());
        if(x>=INT_MAX-1){
            return -1;
        }
        return x;
    }
};