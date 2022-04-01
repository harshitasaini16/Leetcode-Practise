class Solution {
public:
    int dp[27][27][301];
    int fun(string s,int f1,int f2,int i){
        if(i>=s.length()){
            return 0;
        }
        if(dp[f1+1][f2+1][i]!=-1){
            return dp[f1+1][f2+1][i];
        }
        int kk=s[i]-'A';
        pair<int,int>a={kk/6, kk%6};
        int t1=(f1==-1)?0:(abs(a.first-f1/6)+abs(a.second-f1%6));
        int t2=(f2==-1)?0:(abs(a.first-f2/6)+abs(a.second-f2%6));
        int ans1=t1+fun(s,kk,f2,i+1);
        int ans2=t2+fun(s,f1,kk,i+1);
        return dp[f1+1][f2+1][i]=min(ans1,ans2);
    }
    int minimumDistance(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(s,-1,-1,0);
        
    }
};