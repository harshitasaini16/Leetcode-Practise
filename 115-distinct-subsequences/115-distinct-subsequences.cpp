class Solution {
public:
    int dp[1001][1001];
    int fun(string s,string t,int n,int m){
        if(m==0){
            return 1;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(n==0 || m==0){
            return 0;
        }
        if(s[n-1]==t[m-1]){
            return dp[n][m]=(fun(s,t,n-1,m-1)+fun(s,t,n-1,m));
        }
        return dp[n][m]=fun(s,t,n-1,m);
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int n=s.length();
        int m=t.length();
        return fun(s,t,n,m);
    }
};