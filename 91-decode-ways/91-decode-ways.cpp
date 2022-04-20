class Solution {
public:
    int dp[101];
    int fun(string s,int x){
        if(x==s.length()){
            return 1;
        }
        if(s[x]=='0'){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int y=0;
        int ans=0;
        for(int i=x;i<min((int)s.length(),x+3);i++){
            y=y*10+(s[i]-'0');
            if(y>=1 && y<=26){
                ans+=fun(s,i+1);
            }
        }
        return dp[x]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(s,0);
    }
};