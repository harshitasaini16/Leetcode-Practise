class Solution {
public:
    int dp[2001][2001];
    int fun(int x,vector<vector<int>>& piles,int k,int n){
        if(x==piles.size()){
          return 0;
        }
        if(dp[x][k]!=-1){
            return dp[x][k];
        }
        int ans=0;
        int s=0;
        for(int i=0;i<min(k,(int)piles[x].size());i++){
            s+=piles[x][i];
            int y=s+fun(x+1,piles,k-i-1,n);
            ans=max(ans,y);
        }
        return dp[x][k]=max(ans,fun(x+1,piles,k,n));
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        return fun(0,piles,k,n);
    }
};