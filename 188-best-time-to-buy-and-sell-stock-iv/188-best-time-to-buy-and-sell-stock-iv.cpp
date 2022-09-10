class Solution {
public:
    int dp[1001][101][3];
    int fun(int x, vector<int>& prices,int k,int f){
        if(x>=prices.size() || k==0){
            return 0;
        }
        if(dp[x][k][f]!=-1){
            return dp[x][k][f];
        }
        if(f==0){
            return dp[x][k][f]=max(-prices[x]+fun(x+1,prices,k,1),fun(x+1,prices,k,0));
        }
        else{
            return dp[x][k][f]=max(prices[x]+fun(x+1,prices,k-1,0),fun(x+1,prices,k,1));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return fun(0,prices,k,0);
    }
};