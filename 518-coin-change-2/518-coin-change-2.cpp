class Solution {
public:
    int dp[50001][301];
    int fun(int amount, vector<int>& coins,int n){
        if(amount==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[amount][n]!=-1){
            return dp[amount][n];
        }
        if(coins[n-1]>amount){
            return dp[amount][n]=fun(amount,coins,n-1);
        }
        return dp[amount][n]=fun(amount-coins[n-1],coins,n)+fun(amount,coins,n-1);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        sort(coins.begin(),coins.end());
        return fun(amount,coins,coins.size());
    }
};