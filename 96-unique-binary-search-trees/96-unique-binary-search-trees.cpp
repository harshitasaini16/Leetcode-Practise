class Solution {
public:
    int numTrees(int n) {
        int ans=0;
        vector<int>dp;
        dp.push_back(1);
        for(int i=1;i<=n;i++){
            int ans=0;
            for(int j=0;j<i;j++){
                ans+=dp[j]*dp[i-j-1];
            }
            dp.push_back(ans);
        }
        return dp.back();
    }
};