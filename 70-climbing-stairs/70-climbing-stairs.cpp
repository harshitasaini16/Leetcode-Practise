class Solution {
public:
    map<int,int>dp;
    int fun(int n){
        if(n==0){
            return 1;
        }
        else if(n<0){
            return 0;
        }
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        return dp[n]=fun(n-1)+fun(n-2);
    }
    int climbStairs(int n) {
        dp.clear();
        return fun(n);
    }
};