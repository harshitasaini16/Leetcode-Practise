class Solution {
public:
    int mod=1e9+7;
    int dp[100005][3];
    int fun(int x,string &s,int c){
        if(x>=s.length()){
            if(c==2){
                return 1;
            }
            return 0;
        }
        if(dp[x][c]!=-1){
            return dp[x][c];
        }
        if(s[x]=='S'){
            c++;
        }
        if(c==2){
            return dp[x][c]=(fun(x+1,s,0)+fun(x+1,s,c))%mod;
        }
        if(c<2){
            return dp[x][c]=fun(x+1,s,c)%mod;
        }
        return 0;
    }
    int numberOfWays(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(0,s,0)%mod;
    }
};