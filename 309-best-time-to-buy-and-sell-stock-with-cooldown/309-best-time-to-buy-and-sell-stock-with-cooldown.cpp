class Solution {
public:
    int dp[5001][2];
    int fun(int x,vector<int>& prices,int bs){
        if(x>=prices.size()){
            return 0;
        }
        if(dp[x][bs]!=-1){
            return dp[x][bs];
        }
        if(bs==0){
            return dp[x][bs]=max(-prices[x]+fun(x+1,prices,1),fun(x+1,prices,0));
        }
        else{
            return dp[x][bs]=max(prices[x]+fun(x+2,prices,0),fun(x+1,prices,1));
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return fun(0,prices,0);
    }
};