class Solution {
public:
    map<string,bool>dp;
    bool fun(string s1,string s2){
        int n=s1.length();
        int m=s2.length();
        if(n!=m){
            return false;
        }
        if(n==0){
            return true;
        }
        if(s1==s2){
            return true;
        }
        string s=s1+' '+s2;
        if(dp.find(s)!=dp.end()){
            return dp[s];
        }
        for(int i=0;i<n-1;i++){
            if(fun(s1.substr(0,i+1),s2.substr(n-i-1,i+1)) && fun(s1.substr(i+1),s2.substr(0,n-i-1))){
                return dp[s]=true;
            }
            if(fun(s1.substr(0,i+1),s2.substr(0,i+1)) && fun(s1.substr(i+1),s2.substr(i+1))){
                return dp[s]=true;
            }
        }
        return dp[s]=false;
    }
    bool isScramble(string s1, string s2) {
        dp.clear();
        return fun(s1,s2);
    }
};