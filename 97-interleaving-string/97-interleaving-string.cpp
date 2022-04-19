class Solution {
public:
    int dp[101][101][201];
    int fun(int n,int m,int k,string s1,string s2,string s3){
        if(n==0 && m==0 && k==0){
            return 1;
        }
        if(dp[n][m][k]!=-1){
            return dp[n][m][k]=dp[n][m][k];
        }
        int f=0;
        if(m>0){
            if(s2[m-1]==s3[k-1]){
                if(fun(n,m-1,k-1,s1,s2,s3)==1){
                    f=1;
                }
            }
        }
        if(n>0){
            if(s1[n-1]==s3[k-1]){
                if(fun(n-1,m,k-1,s1,s2,s3)==1){
                    f=1;
                }
            }
        }
        return dp[n][m][k]=f;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        return fun(s1.length(),s2.length(),s3.length(),s1,s2,s3);
    }
};