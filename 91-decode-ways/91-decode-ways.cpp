class Solution {
public:
    int dp[101];
    int fun(string s,int i,int n){
        if(i>=n){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        string s1=s.substr(i,1);
        ans=fun(s,i+1,n);
        if(i+1<n){
            string s2=s.substr(i,2);
            int k=stoi(s2);
            if(k>0 and k<27){
                ans+=fun(s,i+2,n);
            }
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(s,0,s.length());
    }
};