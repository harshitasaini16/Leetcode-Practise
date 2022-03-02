class Solution {
public:
    map<pair<int,int>,int>dp;
    bool f(string s,string t,int n,int m){
        if(n==0 && m==0){
            return true;
        }
        if(n==0){
            return true;
        }
        if(m==0){
            return false;
        }
        if(dp.find({n,m})!=dp.end()){
            return dp[{n,m}];
        }
        if(s[n-1]!=t[m-1]){
            return dp[{n,m}]=f(s,t,n,m-1);
        }
        return dp[{n,m}]=(f(s,t,n,m-1)||f(s,t,n-1,m-1));
    }
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        dp.clear();
        return f(s,t,n,m);
    }
};