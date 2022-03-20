class Solution {
public:
    int dp[1001][1001];
    int fun(string &s1,string &s2,int n,int m){
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]=1+fun(s1,s2,n-1,m-1);
        }
        return dp[n][m]=max(fun(s1,s2,n-1,m),fun(s1,s2,n,m-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return fun(text1,text2,text1.length(),text2.length());
    }
};