class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        if(n<=2){
            return n;
        }
        int ans=2;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=nums[j]-nums[i]+1000;
                dp[j][k]=max(dp[i][k]+1,2);
                ans=max(ans,dp[j][k]);
            }
        }
        return ans;
    }
};