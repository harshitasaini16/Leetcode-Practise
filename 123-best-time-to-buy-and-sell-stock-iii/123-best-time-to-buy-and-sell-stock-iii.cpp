class Solution {
public:
    int dp[100001][3][3];
    int fun(int x,vector<int>& prices,int cap,int v){
        if(x==prices.size()){
            return 0;
        }
        if(cap==0){
            return 0;
        }
        if(dp[x][cap][v]!=-1){
            return dp[x][cap][v];
        }
        if(v==0){
            return dp[x][cap][v]=max(-prices[x]+fun(x+1,prices,cap,1),fun(x+1,prices,cap,0));
        }
        else{
            return dp[x][cap][v]=max(prices[x]+fun(x+1,prices,cap-1,0),fun(x+1,prices,cap,1));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,prices,2,0);
    }
};