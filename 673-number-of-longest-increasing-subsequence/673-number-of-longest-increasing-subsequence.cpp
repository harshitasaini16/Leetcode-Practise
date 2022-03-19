class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        int mx=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]==dp[i]-1){
                    count[i]=count[i]+count[j];
                }
                else if(nums[j]<nums[i] && dp[j]>=dp[i]){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                mx=max(mx,dp[i]);
            }
        }
        int s=0;
        for(int i=0;i<n;i++){
            if(dp[i]==mx){
                s+=count[i];
            }
        }
        return s;
    }
};