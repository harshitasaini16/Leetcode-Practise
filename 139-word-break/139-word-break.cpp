class Solution {
public:
    int dp[1001];
    bool fun(int x,string &s,map<string,int>m){
        if(x>=s.length()){
            return true;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        for(int i=x;i<s.length();i++){
            string temp=s.substr(x,i-x+1);
            if(m[temp]>0){
                if(fun(i+1,s,m)){
                    return dp[x]=true;
                }
            }
        }
        return dp[x]=false;
    }
    bool wordBreak(string s, vector<string>& d) {
        memset(dp,-1,sizeof(dp));
        map<string,int>m;
        for(int i=0;i<d.size();i++){
            m[d[i]]++;
        }
        return fun(0,s,m);
    }
};