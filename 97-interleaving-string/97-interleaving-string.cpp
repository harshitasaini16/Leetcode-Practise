class Solution {
public:
    int dp[101][101][201];
    bool fun(string s1,string s2,string s3,int n,int m,int k){
        if(n==0 && m==0 && k==0){
            return true;
        }
        if(dp[n][m][k]!=-1){
            return dp[n][m][k];
        }
        bool f=false;
        if(n>0){
            if(s1[n-1]==s3[k-1]){
                f=(f || fun(s1,s2,s3,n-1,m,k-1));
            }
        }
        if(m>0){
            if(s2[m-1]==s3[k-1]){
                f=(f || fun(s1,s2,s3,n,m-1,k-1));
            }
        }
        return dp[n][m][k]=f;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        return fun(s1,s2,s3,s1.length(),s2.length(),s3.length());
    }
};