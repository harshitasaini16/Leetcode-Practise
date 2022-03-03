class Solution {
public:
    int dp[10001][13];
    int f(int n,int amount,vector<int>& coins){
        if(amount==0){
            return 0;
        }
        if(n==0){
            return INT_MAX-1;
        }
        if(dp[amount][n]!=-1){
            return dp[amount][n];
        }
        if(coins[n-1]<=amount){
            return dp[amount][n]=min(1+f(n,amount-coins[n-1],coins),f(n-1,amount,coins));
        }
        else{
            return dp[amount][n]=f(n-1,amount,coins);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        memset(dp,-1,sizeof(dp));
        int x=f(coins.size(),amount,coins);
        if(x==INT_MAX-1 || x==INT_MAX){
            return -1;
        }
        return x;
    }
};