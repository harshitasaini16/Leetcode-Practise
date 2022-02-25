class Solution {
public:
    map<pair<int,int>,int>dp;
    int fun(int n,int m,string s1,string s2){
        if(n==0 && m==0){
            return 0;
        }
        if(n==0){
            return m;
        }
        else if(m==0){
            return n;
        }
        if(dp.find({n,m})!=dp.end()){
            return dp[{n,m}];
        }
        if(s1[n-1]==s2[m-1]){
            return dp[{n,m}]=min(fun(n-1,m-1,s1,s2),1+fun(n,m-1,s1,s2));
        }
        return dp[{n,m}]=min({1+fun(n,m-1,s1,s2),1+fun(n-1,m-1,s1,s2),1+fun(n-1,m,s1,s2)});
    }
    int minDistance(string word1, string word2) {
        return fun(word1.length(),word2.length(),word1,word2);
    }
};