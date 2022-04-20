class Solution {
public:
    int dp[2001][2001];
    bool check(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int fun(int x,int y,string &s){
        if(x>=y){
            return 0;
        }
        if(check(x,y,s)){
            return 0;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int ans=INT_MAX;
        for(int i=x;i<=y;i++){
            if(check(x,i,s)){
                ans=min(ans,fun(i+1,y,s));
            }
        }
        return dp[x][y]=ans+1;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(0,s.length()-1,s);
    }
};