class Solution {
public:
    int dp[2001][2001];
    bool check(string &s,int x,int y){
       if(dp[x][y]!=-1){
           return 0;
       }
        while(x<y){
            if(s[x]!=s[y]){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    int fun(int x,int n,string &s){
        if(x>=n || check(s,x,n)){
            return dp[x][n]=0;
        }
        if(dp[x][n]!=-1){
            return dp[x][n];
        }
        int ans=INT_MAX;
        for(int i=x;i<n;i++){
            if(check(s,x,i)){
                ans=min(ans,1+fun(i+1,n,s));
            }
        }
        return dp[x][n]=ans;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(0,s.length()-1,s);
    }
};