class Solution {
public:
    map<pair<int,char>,int>dp;
    int fun(int x,int n,string s,char c){
        if(x==n){
            return 1;
        }
        if(dp.find({x,c})!=dp.end()){
            return dp[{x,c}];
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]<=c){
                ans+=fun(x+1,n,s,s[i]);
            }
        }
        return dp[{x,c}]=ans;
    }
    int countVowelStrings(int n) {
        string s="aeiou";
        int ans=0;
        dp.clear();
        for(int i=0;i<s.length();i++){
            ans+=fun(1,n,s,s[i]);
        }
        return ans;
    }
};