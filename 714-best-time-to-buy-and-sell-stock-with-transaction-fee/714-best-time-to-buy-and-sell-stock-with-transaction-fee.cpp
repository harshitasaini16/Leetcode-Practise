class Solution {
public:
    int dp[100001][2];
    int fun(int x,vector<int>& prices,int bs,int fee){
        if(x>=prices.size()){
            return 0;
        }
        if(dp[x][bs]!=-1){
            return dp[x][bs];
        }
        if(bs==0){
            return dp[x][bs]=max(-prices[x]+fun(x+1,prices,1,fee),fun(x+1,prices,0,fee));
        }
        else{
            return dp[x][bs]=max(prices[x]-fee+fun(x+1,prices,0,fee),fun(x+1,prices,1,fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return fun(0,prices,0,fee);
    }
};