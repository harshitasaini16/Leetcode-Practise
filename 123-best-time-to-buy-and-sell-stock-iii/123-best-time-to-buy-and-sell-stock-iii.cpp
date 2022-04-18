class Solution {
public:
    int dp[100001][3][3];
    int fun(int x,vector<int>& prices,int l,int c){
        if(x==prices.size()){
            return 0;
        }
        if(c==2){
            return 0;
        }
        if(dp[x][l][c]!=-1){
            return dp[x][l][c];
        }
        if(l==1){
            return dp[x][l][c]=max(fun(x+1,prices,l,c),-prices[x]+fun(x+1,prices,2,c));
        }
        else if(l==2){
            return dp[x][l][c]=max(fun(x+1,prices,l,c),prices[x]+fun(x+1,prices,1,c+1));
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return fun(0,prices,1,0);
    }
};